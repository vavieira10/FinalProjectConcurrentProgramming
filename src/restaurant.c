#include "restaurant.h"

pthread_mutex_t mutexRestaurant = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexRestaurant2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexRestaurant3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexRestaurant4 = PTHREAD_MUTEX_INITIALIZER;

void *restaurantClient(void *arg){
    int clientId = *(int*) arg;
    int cashierToAwake = 0;

    while(1){
        printf("%sCLIENTE RESTAURANTE %d| Chegando no restaurante e vendo se tem caixa disponivel %s\n", ANSI_COLOR_BLUE, clientId, RESET_COLOR);

        // Arrives at the restarant and checks if theres any cashier avaiable
        sem_wait(&sem_restaurantCashier);
        pthread_mutex_lock(&mutexRestaurant2);
        cashierToAwake = checkWhichIsUsed(freeRestaurantCashier, RESTAURANT_CASHIERS);
        freeRestaurantCashier[cashierToAwake] = 0;
        pthread_mutex_unlock(&mutexRestaurant2);
        sem_post(&sem_wakeCashier[cashierToAwake]); // wakes the thread of a free cashier 

        // if there's any cashier avaiable, the client does his order
        printf("%sCLIENTE RESTAURANTE %d| Caixa %d disponivel! %s\n", ANSI_COLOR_BLUE, clientId, cashierToAwake,RESET_COLOR);
        sleep(3);
        printf("%sCLIENTE RESTAURANTE %d| Fazendo o pedido para o caixa %s\n", ANSI_COLOR_BLUE, clientId, RESET_COLOR);
        sleep(5);
        printf("%sCLIENTE RESTAURANTE %d| Esperando o pedido ficar pronto %s\n", ANSI_COLOR_BLUE, clientId, RESET_COLOR);
        // will be blocked until the meal is ready
        pthread_mutex_lock(&mutexRestaurant);
        orderClientRestaurant[clientId] = 1;
        pthread_mutex_unlock(&mutexRestaurant);

        sleep(3);
        sem_wait(&sem_sleepClientRestaurant[clientId]);

        printf("%sCLIENTE RESTAURANTE %d| Lanche pronto, pegando o lanche %s\n", ANSI_COLOR_BLUE, clientId, RESET_COLOR);
        sem_wait(&sem_wakeCashier[cashierToAwake]);
        printf("%sCLIENTE RESTAURANTE %d| Indo comer o lanche %s\n", ANSI_COLOR_BLUE, clientId, RESET_COLOR);

    }

    pthread_exit(0);
}

void *restaurantCashier(void *arg){
    int cashierId = *(int*) arg;
    int mealReadyCashier = 0;

    while(1){
        printf("%sCAIXA RESTAURANTE %d| Esperando clientes %s\n", ANSI_COLOR_BLUE, cashierId, RESET_COLOR);

        // the cashier employee is blocked until a client calls him
        sem_wait(&sem_wakeCashier[cashierId]);
        printf("%sCAIXA RESTAURANTE %d| Atendendo um cliente e anotando o pedido %s\n", ANSI_COLOR_BLUE, cashierId, RESET_COLOR);
        sleep(11);

        // the restaurant cashier will let the meal cashier employee know the order
        printf("%sCAIXA RESTAURANTE %d| Vendo se tem algum caixa para entregar o pedido livre %s\n", ANSI_COLOR_BLUE, cashierId, RESET_COLOR);
        sem_wait(&sem_restaurantMealCashier);

        // waking the meal cashier
        pthread_mutex_lock(&mutexRestaurant3);
        mealReadyCashier = checkWhichIsUsed(freeMealReady, MEAL_REST_CASHIERS);
        freeMealReady[mealReadyCashier] = 0;
        pthread_mutex_unlock(&mutexRestaurant3);
        sem_post(&sem_wakeMealCashier[mealReadyCashier]);
        freeRestaurantCashier[cashierId] = 1;
        printf("%sCAIXA RESTAURANTE %d| Mandou o pedido para o caixa de entrega de pedidos %d %s\n", ANSI_COLOR_BLUE, cashierId, mealReadyCashier, RESET_COLOR);
        sleep(2);
        sem_post(&sem_restaurantCashier);
    }
   
    pthread_exit(0);
}

void *restaurantMealReadyCashier(void *arg){
    int mealReadyId = *((int *)arg);
    int orderFromClient = 0;

    while(1){
        printf("%sCAIXA ENTREGA PEDIDO RESTAURANTE %d| Esperando algum pedido a ser montado %s\n", ANSI_COLOR_BLUE, mealReadyId, RESET_COLOR);

        // the restaurant employee is blocked until a client calls him
        sem_wait(&sem_wakeMealCashier[mealReadyId]);
        sleep(2);
        pthread_mutex_lock(&mutexRestaurant4);
        orderFromClient = checkWhichIsUsed(orderClientRestaurant, RESTAURANT_CLIENTS);
        orderClientRestaurant[orderFromClient] = -1;
        pthread_mutex_unlock(&mutexRestaurant4);
        printf("%sCAIXA ENTREGA PEDIDO RESTAURANTE %d| Pedido para preparar lanche recebido! Indo entregar para o cliente %d %s\n", ANSI_COLOR_BLUE, mealReadyId, orderFromClient, RESET_COLOR);
        sleep(11);

        printf("%sCAIXA ENTREGA PEDIDO RESTAURANTE %d| Pedido do cliente %d pronto %s\n", ANSI_COLOR_BLUE, mealReadyId, orderFromClient, RESET_COLOR);
        sleep(4);
        sem_post(&sem_sleepClientRestaurant[orderFromClient]);
        sleep(5);
        printf("%sCAIXA ENTREGA PEDIDO RESTAURANTE %d| Entregou para o cliente %d, esperando novos pedidos %s\n", ANSI_COLOR_BLUE, mealReadyId, orderFromClient, RESET_COLOR);

        freeMealReady[mealReadyId] = 1;
        sleep(2);
        sem_post(&sem_restaurantMealCashier);
    }
   
    pthread_exit(0);
}
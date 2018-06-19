#include "delivery.h"

pthread_mutex_t mutexDelivery = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexDelivery2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexDelivery3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexDelivery4 = PTHREAD_MUTEX_INITIALIZER;

sem_t sem_deliveryEmployee;
sem_t sem_wakeDeliveryEmployee[DELIVERY_EMLOYEES];

sem_t sem_motoboy;
sem_t sem_wakeMotoboy[MOTOBOYS];

sem_t sem_sleepClientDelivery[DELIVERY_CLIENTS];

int freeMotoboys[MOTOBOYS];
int freeDeliveryEmployee[DELIVERY_EMLOYEES];
int orderClientDelivery[DELIVERY_CLIENTS];

void *deliveryEmployee(void *arg){
    int employeeId = *(int*) arg;
    int motoboyToAwake = 0;

    while(1){
        printf("%sATENDENTE DELIVERY %d| Esperando ligacao %s\n", ANSI_COLOR_GREEN, employeeId, RESET_COLOR);

        // the delivery employee is blocked until a client calls him
        sem_wait(&sem_wakeDeliveryEmployee[employeeId]);
        printf("%sATENDENTE DELIVERY %d| Atendendo um cliente e anotando o pedido %s\n", ANSI_COLOR_GREEN, employeeId, RESET_COLOR);
        sleep(11);
        // the delivery employee will wake the motoboy
        printf("%sATENDENTE DELIVERY %d| Verificando se tem algum motoboy livre para entrega %s\n", ANSI_COLOR_GREEN, employeeId, RESET_COLOR);
        sem_wait(&sem_motoboy);
        // waking the motoboy
        pthread_mutex_lock(&mutexDelivery2);
        motoboyToAwake = checkWhichIsUsed(freeMotoboys, MOTOBOYS);
        freeMotoboys[motoboyToAwake] = 0;
        pthread_mutex_unlock(&mutexDelivery2);
        sem_post(&sem_wakeMotoboy[motoboyToAwake]);
        freeDeliveryEmployee[employeeId] = 1;
        printf("%sATENDENTE DELIVERY %d| Mandou o pedido para o motoboy %d %s\n", ANSI_COLOR_GREEN, employeeId, motoboyToAwake, RESET_COLOR);
        sleep(2);
        sem_post(&sem_deliveryEmployee);
    }

    pthread_exit(0);
}

void *deliveryClient(void *arg){
    int clientId = *(int*) arg;
    int employeeToAwake = 0;

    while(1){
        printf("%sCLIENTE DELIVERY %d| Ligando para o atendimento do delivery %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);

        // calling for the delivery service  and 
        // checking if there's a customer avaiable
        sem_wait(&sem_deliveryEmployee);
        pthread_mutex_lock(&mutexDelivery4);
        employeeToAwake = checkWhichIsUsed(freeDeliveryEmployee, DELIVERY_EMLOYEES);
        freeDeliveryEmployee[employeeToAwake] = 0;
        pthread_mutex_unlock(&mutexDelivery4);
        sem_post(&sem_wakeDeliveryEmployee[employeeToAwake]); // wakes the thread of customer 
        // if there's any customer avaiable, the client complete his call
        printf("%sCLIENTE DELIVERY %d| Atendente atendeu o telefone %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);
        sleep(3);
        printf("%sCLIENTE DELIVERY %d| Fazendo o pedido para o atendente do delivery %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);
        sleep(5);
        printf("%sCLIENTE DELIVERY %d| Fez o pedido, aguardando o motoboy chegar %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);
        sleep(2);

        // will be blocked until the motoboy arrives
        pthread_mutex_lock(&mutexDelivery);
        orderClientDelivery[clientId] = 1;
        pthread_mutex_unlock(&mutexDelivery);

        sleep(3);
        sem_wait(&sem_sleepClientDelivery[clientId]);

        printf("%sCLIENTE DELIVERY %d| Motoboy chegou, pegando e pagando o lanche %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);
        sleep(5);
        sem_wait(&sem_wakeDeliveryEmployee[employeeToAwake]);
        printf("%sCLIENTE DELIVERY %d| Indo comer o lanche %s\n", ANSI_COLOR_GREEN, clientId, RESET_COLOR);

    }
   
    pthread_exit(0);
}

void *deliveryMotoboy(void *arg){
    int motoboyId = *((int *)arg);
    int clientToDeliverOrder = 0;

    while(1){
        printf("%sMOTOBOY DELIVERY %d| Esperando alguma entrega %s\n", ANSI_COLOR_GREEN, motoboyId, RESET_COLOR);

        // the delivery motoboy is blocked until a client calls him
        sem_wait(&sem_wakeMotoboy[motoboyId]);
        pthread_mutex_lock(&mutexDelivery3);
        clientToDeliverOrder = checkWhichIsUsed(orderClientDelivery, DELIVERY_CLIENTS);
        orderClientDelivery[clientToDeliverOrder] = -1;
        pthread_mutex_unlock(&mutexDelivery3);
        printf("%sMOTOBOY DELIVERY %d| Pedido para entrega recebido! indo entregar para o cliente %d %s\n", ANSI_COLOR_GREEN, motoboyId, clientToDeliverOrder, RESET_COLOR);
        sleep(11);
        
        printf("%sMOTOBOY DELIVERY %d| Chegou na casa do cliente %d %s\n", ANSI_COLOR_GREEN, motoboyId, clientToDeliverOrder, RESET_COLOR);
        sleep(3);
        sem_post(&sem_sleepClientDelivery[clientToDeliverOrder]);
        sleep(5);
        printf("%sMOTOBOY DELIVERY %d| Entregou para o cliente %d, voltando para a loja %s\n", ANSI_COLOR_GREEN, motoboyId, clientToDeliverOrder, RESET_COLOR);

        freeMotoboys[motoboyId] = 1;
        sleep(2);
        sem_post(&sem_motoboy);
    }
   
    pthread_exit(0);
}
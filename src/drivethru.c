#include "drivethru.h"

sem_t sem_drivethruOrder;
pthread_mutex_t lock_driveThruOrder = PTHREAD_MUTEX_INITIALIZER;

sem_t sem_drivethruPayment;
pthread_mutex_t lock_drivethruPayment = PTHREAD_MUTEX_INITIALIZER;

sem_t sem_drivethruTakeOrder;
pthread_mutex_t lock_drivethruTakeOrder = PTHREAD_MUTEX_INITIALIZER;

void *drivethruCar(void *arg){
    int carId = *(int*) arg;

    while(1){
        printf("%sCARRO %d| Entrando na fila do drive-thru %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);

        // checking if there's another car ordering, if there's any
        // the thread will be blocked until is his turn
        pthread_mutex_lock(&lock_driveThruOrder);
        sem_post(&sem_drivethruOrder); 
        // if there's no one, the customer in the car will order his meal
        printf("%sCARRO %d| Fazendo o pedido no caixa de pedidos %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        sleep(10);
        pthread_mutex_unlock(&lock_driveThruOrder);
        printf("%sCARRO %d| Fez o pedido, indo para o caixa de pagamento se nao tiver ninguem %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        sleep(3);
        
        pthread_mutex_lock(&lock_drivethruPayment);
        sem_post(&sem_drivethruPayment);
        // if there's no one, the customer will pay for his meal
        printf("%sCARRO %d| Pagando a refeicao no caixa de pagamentos %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        sleep(10);
        printf("%sCARRO %d| Efetuou o pagamento, indo para o caixa pegar a refeicao, se nao tiver ninguem %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        pthread_mutex_unlock(&lock_drivethruPayment);
        sleep(3);

        pthread_mutex_lock(&lock_drivethruTakeOrder);
        sem_post(&sem_drivethruTakeOrder);
        // if there's no one, the customer will take his meal
        printf("%sCARRO %d| Pegando a refeicao no caixa para pegar a refeicao %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        sleep(10);
        pthread_mutex_unlock(&lock_drivethruTakeOrder);
        printf("%sCARRO %d| Indo embora %s\n", ANSI_COLOR_RED, carId, RESET_COLOR);
        sleep(5);
    }

    pthread_exit(0);
}

void *drivethruOrder(void *arg){

    while(1){
        printf("%sDRIVE-THRU CAIXA DE PEDIDOS| Aguardando carros %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sem_wait(&sem_drivethruOrder);
        printf("%sDRIVE-THRU CAIXA DE PEDIDOS| Carro chegou para ser atendido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE PEDIDOS| Atendendo carro %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE PEDIDOS| Carro atendido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
    }

    pthread_exit(0);
}

void *drivethruPayment(void *arg){

   while(1){
        printf("%sDRIVE-THRU CAIXA DE PAGAMENTO| Aguardando carros %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sem_wait(&sem_drivethruOrder);
        printf("%sDRIVE-THRU CAIXA DE PAGAMENTO| Carro chegou para pagar o pedido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE PAGAMENTO| Atendendo carro %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE PAGAMENTO| Carro atendido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
    }

    pthread_exit(0);
}

void *drivethruTakeOrders(void *arg){

    while(1){
        printf("%sDRIVE-THRU - CAIXA DE ENTREGA DE PEDIDOS %s\n", ANSI_COLOR_RED, RESET_COLOR);
        printf("%sDRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Aguardando carros %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sem_wait(&sem_drivethruOrder);
        printf("%sDRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Carro chegou para pegar o pedido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Entregando o pedido para o carro %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
        printf("%sDRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Carro atendido %s\n", ANSI_COLOR_RED, RESET_COLOR);
        sleep(3);
    }

    pthread_exit(0);
}
#include "drivethru.h"

void *drivethruCar(void *arg){
    int carId = *(int*) arg;

    while(1){
        printf("DRIVE-THRU - CARRO %d\n", carId);
        printf("CARRO %d| Entrando na fila do drive-thru\n", carId);

        // checking if there's another car ordering, if there's any
        // the thread will be blocked until is his turn
        pthread_mutex_lock(&lock_driveThruOrder);
        sem_post(&sem_drivethruOrder); 
        // if there's no one, the customer in the car will order his meal
        printf("CARRO %d| Fazendo o pedido no caixa de pedidos\n", carId);
        sleep(10);
        pthread_mutex_unlock(&lock_driveThruOrder);
        printf("CARRO %d| Fez o pedido, indo para o caixa de pagamento se nao tiver ninguem\n", carId);
        sleep(3);
        
        pthread_mutex_lock(&lock_drivethruPayment);
        sem_post(&sem_drivethruPayment);
        // if there's no one, the customer will pay for his meal
        printf("CARRO %d| Pagando a refeicao no caixa de pagamentos\n", carId);
        sleep(10);
        printf("CARRO %d| Efetuou o pagamento, indo para o caixa pegar a refeicao, se nao tiver ninguem\n", carId);
        pthread_mutex_unlock(&lock_drivethruPayment);
        sleep(3);

        pthread_mutex_lock(&lock_drivethruTakeOrder);
        sem_post(&sem_drivethruTakeOrder);
        // if there's no one, the customer will take his meal
        printf("CARRO %d| Pegando a refeicao no caixa para pegar a refeicao\n", carId);
        sleep(10);
        pthread_mutex_unlock(&lock_drivethruTakeOrder);
        printf("CARRO %d| Indo embora\n", carId);
        sleep(5);
    }

    pthread_exit(0);
}

void *drivethruOrder(void *arg){

    while(1){
        printf("DRIVE-THRU - CAIXA DE PEDIDOS\n");
        printf("DRIVE-THRU CAIXA DE PEDIDOS| Aguardando carros\n");
        sem_wait(&sem_drivethruOrder);
        printf("DRIVE-THRU CAIXA DE PEDIDOS| Carro chegou para ser atendido\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE PEDIDOS| Atendendo carro\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE PEDIDOS| Carro atendido\n");
        sleep(3);
    }

    pthread_exit(0);
}

void *drivethruPayment(void *arg){

   while(1){
        printf("DRIVE-THRU - CAIXA DE PAGAMENTO\n");
        printf("DRIVE-THRU CAIXA DE PAGAMENTO| Aguardando carros\n");
        sem_wait(&sem_drivethruOrder);
        printf("DRIVE-THRU CAIXA DE PAGAMENTO| Carro chegou para pagar o pedido\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE PAGAMENTO| Atendendo carro\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE PAGAMENTO| Carro atendido\n");
        sleep(3);
    }

    pthread_exit(0);
}

void *drivethruTakeOrders(void *arg){

    while(1){
        printf("DRIVE-THRU - CAIXA DE ENTREGA DE PEDIDOS\n");
        printf("DRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Aguardando carros\n");
        sem_wait(&sem_drivethruOrder);
        printf("DRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Carro chegou para pegar o pedido\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Entregando o pedido para o carro\n");
        sleep(3);
        printf("DRIVE-THRU CAIXA DE ENTREGA DE PEDIDOS| Carro atendido\n");
        sleep(3);
    }

    pthread_exit(0);
}
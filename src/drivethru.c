#include "drivethru.h"

void *drivethruCar(void *arg){
    int carId = *(int*) arg;

    while(1){
        printf("DRIVE-THRU - Carro %d\n", carId);
        printf("Carro %d| Entrando na fila do drive-thru\n", carId);
        // checking if there's another car ordering, if there's any
        // the thread will be blocked until is his turn
        sem_wait(&sem_drivethruOrder); 
        // if there's no one, the customer in the car will order his meal
        printf("Carro %d| Fazendo o pedido no caixa de pedidos\n", carId);
        sleep(5);
        // TODO: enviar pedido para a cozinha
        printf("Carro %d| Fez o pedido, indo para o caixa de pagamento se nao tiver ninguem\n", carId);
        sleep(3);
        sem_wait(&sem_drivethruPayment);
        // if there's no one, the customer will pay for his meal
        printf("Carro %d| Pagando a refeicao no caixa de pagamentos\n", carId);
        sleep(5);
        printf("Carro %d| Efetuou o pagamento, indo para o caixa pegar a refeicao, se nao tiver ninguem\n", carId);
        sleep(3);
        sem_wait(&sem_drivethruTakeOrder);
        // if there's no one, the customer will take his meal
        printf("Carro %d| Pegando a refeicao no caixa para pegar a refeicao\n", carId);
        sleep(5);
        printf("Carro %d| Indo embora\n", carId);
        sleep(5);
    }

    pthread_exit(0);
}

void *drivethruOrder(void *arg){

    // while(1){
    //     sem_wait(&temCliente); 
    //     sleep(5);
    //     sem_post(&cabeloCortado);

    // }

    pthread_exit(0);
}

void *drivethruPayment(void *arg){

    // while(1){
    //     sem_wait(&temCliente); 
    //     sleep(5);
    //     sem_post(&cabeloCortado);

    // }

    pthread_exit(0);
}

void *drivethruTakeOrders(void *arg){

    // while(1){
    //     sem_wait(&temCliente); 
    //     sleep(5);
    //     sem_post(&cabeloCortado);

    // }

    pthread_exit(0);
}
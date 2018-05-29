#include "drivethru.h"

void *drivethruCar(void *arg){

    // while(1){
    //     sem_wait(&temCliente); 
    //     sleep(5);
    //     sem_post(&cabeloCortado);

    // }

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
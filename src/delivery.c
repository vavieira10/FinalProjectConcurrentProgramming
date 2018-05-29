#include "delivery.h"

void *deliveryEmployee(void *arg){

    // while(1){
    //     sem_wait(&temCliente); 
    //     sleep(5);
    //     sem_post(&cabeloCortado);

    // }

    pthread_exit(0);
}

void *deliveryClient(void *arg){
    int idCliente = *((int *)arg);

    // while(1){
    //     printf("Cliente %d: Chegou no barbeiro\n", idCliente);
    //     if(sem_trywait(&cadeirasLivres) == 0){
    //         sem_wait(&cadeiraBarbeiro);
    //         sem_post(&cadeirasLivres); 
    //         sleep(3);
    //     }else{
    //         printf("Cliente %d: Barbeiro ocupado e sem cadeiras livres! Indo embora!\n", idCliente);
    //         sleep(7);
    //     }
    // }
   
    pthread_exit(0);
}

void *deliveryMotoboy(void *arg){
    int idCliente = *((int *)arg);

    // while(1){
    //     printf("Cliente %d: Chegou no barbeiro\n", idCliente);
    //     if(sem_trywait(&cadeirasLivres) == 0){
    //         sem_wait(&cadeiraBarbeiro);
    //         sem_post(&cadeirasLivres); 
    //         sleep(3);
    //     }else{
    //         printf("Cliente %d: Barbeiro ocupado e sem cadeiras livres! Indo embora!\n", idCliente);
    //         sleep(7);
    //     }
    // }
   
    pthread_exit(0);
}
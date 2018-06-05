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
    int clientId = *(int*) arg;

    while(1){
        printf("DELIVERY - CLIENTE %d\n", clientId);
        printf("CLIENTE DELIVERY %d| Ligando para o atendimento do delivery\n", clientId);

        // calling for the delivery service  and 
        // checking if there's a customer avaiable
        sem_wait(&sem_deliveryEmployee);
        sem_post(&sem_wakeDeliveryEmployee[genRandomValue(0, DELIVERY_EMLOYEES - 1)]); // wakes the thread of a random customer 
        // if there's any customer avaiable, the client complete his call
        printf("CLIENTE DELIVERY %d| Atendente atendeu o telefone\n", clientId);
        sleep(3);
        printf("CLIENTE DELIVERY %d| Fazendo o pedido para o atendente do delivery\n", clientId);
        sleep(10);
        printf("CLIENTE DELIVERY %d| Fez o pedido, aguardando o motoboy chegar\n", clientId);
        sleep(3);
        sem_wait(&sem_sleepClientDelivery[clientId]);
        sem_post(&sem_drivethruPayment);
        // if there's no one, the customer will pay for his meal
        printf("CLIENTE DELIVERY %d| Pagando a refeicao no caixa de pagamentos\n", clientId);
        sleep(10);
        printf("CLIENTE DELIVERY %d| Efetuou o pagamento, indo para o caixa pegar a refeicao, se nao tiver ninguem\n", clientId);
        pthread_mutex_unlock(&lock_drivethruPayment);
        sleep(3);

        pthread_mutex_lock(&lock_drivethruTakeOrder);
        sem_post(&sem_drivethruTakeOrder);
        // if there's no one, the customer will take his meal
        printf("CLIENTE DELIVERY %d| Pegando a refeicao no caixa para pegar a refeicao\n", clientId);
        sleep(10);
        pthread_mutex_unlock(&lock_drivethruTakeOrder);
        printf("CLIENTE DELIVERY %d| Indo embora\n", clientId);
        sleep(5);
    }
   
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
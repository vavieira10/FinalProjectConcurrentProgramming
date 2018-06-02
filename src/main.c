#include "main.h"
#include "restaurant.h"
#include "delivery.h"
#include "drivethru.h"

int main(){
    int *id = NULL, i = 0;

    // Thread definitions for restaurant
    pthread_t restaurantClients[RESTAURANT_CLIENTS];
    pthread_t restaurantCashiers[RESTAURANT_CASHIERS];
    pthread_t restaurantMealReady[MEAL_REST_CASHIERS];
    // Thread definitions for drive thru
    pthread_t drivethruCars[CARS];
    pthread_t drivethruOrders, drivethruPayments, drivethruTakeOrders;
    // Thread definitions for delivery
    pthread_t deliveryEmployees[DELIVERY_EMLOYEES];
    pthread_t deliveryClients[DELIVERY_CLIENTS];
    pthread_t deliveryMotoboys[MOTOBOYS];

    // Initializing sempahores
    sem_init(&sem_restarauntCashier, 0, RESTAURANT_CASHIERS); 
    sem_init(&sem_restaurantMealCashier, 0, MEAL_REST_CASHIERS); 
    sem_init(&sem_drivethruOrder, 0, 0);
    sem_init(&sem_drivethruPayment, 0, 0); 
    sem_init(&sem_drivethruTakeOrder, 0, 0);
    sem_init(&sem_deliveryEmployee, 0, DELIVERY_EMLOYEES);
    sem_init(&sem_motoboy, 0, MOTOBOYS);
    for(i = 0; i < RESTAURANT_CASHIERS; i++){
        sem_init(&sem_wakeCashier[i], 0, 0);
    }
    for(i = 0; i < MEAL_REST_CASHIERS; i++){
        sem_init(&sem_wakeMealCashier[i], 0, 0);
    }
    for(i = 0; i < DELIVERY_EMLOYEES; i++){
        sem_init(&sem_wakeDeliveryEmployee[i], 0, 0);
    }
    for(i = 0; i < MOTOBOYS; i++){
        sem_init(&sem_wakeMotoboy[i], 0, 0);
    }

    // Creating threads
    for(i = 0; i < RESTAURANT_CLIENTS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&restaurantClients[i], NULL, restaurantClient, (void *) id);
    }
    for(i = 0; i < RESTAURANT_CASHIERS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&restaurantCashiers[i], NULL, restaurantCashier, (void *) id);
    }
    for(i = 0; i < MEAL_REST_CASHIERS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&restaurantMealReady[i], NULL, restaurantMealReadyCashier, (void *) id);
    }
    for(i = 0; i < CARS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&drivethruCars[i], NULL, drivethruCar, (void *) id);
    }
    for(i = 0; i < DELIVERY_EMLOYEES; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&deliveryEmployees[i], NULL, deliveryEmployee, (void *) id);
    }
    for(i = 0; i < DELIVERY_CLIENTS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&deliveryClients[i], NULL, deliveryClient, (void *) id);
    }
    for(i = 0; i < MOTOBOYS; i++){
        id = (int *)malloc(sizeof(int));
        *id = i;
        pthread_create(&deliveryMotoboys[i], NULL, deliveryMotoboy, (void *) id);
    }


    pthread_create(&drivethruOrders, NULL, drivethruOrder, NULL);
    pthread_create(&drivethruPayments, NULL, drivethruOrder, NULL);
    pthread_create(&drivethruTakeOrders, NULL, drivethruOrder, NULL);

    pthread_join(restaurantClients[0], NULL);
    pthread_join(drivethruOrders, NULL);
    pthread_join(drivethruPayments, NULL);
    pthread_join(drivethruTakeOrders, NULL);

    return 0;
}
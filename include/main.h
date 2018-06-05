#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

// Victor Araujo Vieira - 14/0032801

// Global variables for each amount of threads to be used
#define RESTAURANT_CLIENTS 10
#define CARS 10
#define DELIVERY_CLIENTS 10
#define RESTAURANT_CASHIERS 2
#define MEAL_REST_CASHIERS 2
#define DELIVERY_EMLOYEES 3
#define MOTOBOYS 4

// Structs to be used as queues for both delivery and restaurant threads
typedef struct {
    int clientId;
    int flag;
}queue;


queue deliveryQueue[DELIVERY_CLIENTS];
queue restaurantQueue[RESTAURANT_CLIENTS];
int amountQueueDelivery;
int amountQueueRestaurant;

// Function that generates an value between the range [minValue, maxValue]
int genRandomValue(int minValue, int maxValue){
    return (rand() % (maxValue - minValue + 1)) + minValue;
}

// Semaphores definitions to be used
sem_t sem_restarauntCashier;
sem_t sem_wakeCashier[RESTAURANT_CASHIERS];

sem_t sem_restaurantMealCashier;
sem_t sem_wakeMealCashier[MEAL_REST_CASHIERS];

sem_t sem_drivethruOrder;
pthread_mutex_t lock_driveThruOrder = PTHREAD_MUTEX_INITIALIZER;;

sem_t sem_drivethruPayment;
pthread_mutex_t lock_drivethruPayment = PTHREAD_MUTEX_INITIALIZER;;

sem_t sem_drivethruTakeOrder;
pthread_mutex_t lock_drivethruTakeOrder = PTHREAD_MUTEX_INITIALIZER;;

sem_t sem_deliveryEmployee;
sem_t sem_wakeDeliveryEmployee[DELIVERY_EMLOYEES];

sem_t sem_motoboy;
sem_t sem_wakeMotoboy[MOTOBOYS];

sem_t sem_sleepClientDelivery[DELIVERY_CLIENTS];
sem_t sem_sleepClientRestaurant[RESTAURANT_CLIENTS];

#endif
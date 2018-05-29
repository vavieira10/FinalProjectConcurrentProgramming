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

// Semaphores definitions to be used
sem_t sem_restarauntCashier;
sem_t sem_restaurantMealCashier;
sem_t sem_drivethruOrder;
sem_t sem_drivethruPayment;
sem_t sem_drivethruTakeOrder;
sem_t sem_deliveryEmployee;
sem_t sem_motoboy;

#endif
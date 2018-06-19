#ifndef RESTAURANT
#define RESTAURANT

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include "auxiliar.h"

#define RESTAURANT_CLIENTS 3
#define RESTAURANT_CASHIERS 2
#define MEAL_REST_CASHIERS 2

#define ANSI_COLOR_BLUE    "\x1b[34m"
#define RESET_COLOR "\033[0m"

pthread_mutex_t mutexRestaurant, mutexRestaurant2, mutexRestaurant3, mutexRestaurant4;

sem_t sem_restaurantCashier;
sem_t sem_wakeCashier[RESTAURANT_CASHIERS];

sem_t sem_restaurantMealCashier;
sem_t sem_wakeMealCashier[MEAL_REST_CASHIERS];

sem_t sem_sleepClientRestaurant[RESTAURANT_CLIENTS];

int freeRestaurantCashier[RESTAURANT_CASHIERS];
int freeMealReady[MEAL_REST_CASHIERS];
int orderClientRestaurant[RESTAURANT_CLIENTS];

// Function signatures
void *restaurantClient(void *arg);
void *restaurantCashier(void *arg);
void *restaurantMealReadyCashier(void *arg);

#endif
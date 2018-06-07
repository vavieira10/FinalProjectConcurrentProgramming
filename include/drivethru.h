#ifndef DRIVETHRU
#define DRIVETHRU

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include "auxiliar.h"

#define CARS 3
#define ANSI_COLOR_RED     "\x1b[31m"
#define RESET_COLOR "\033[0m"

sem_t sem_drivethruOrder;
pthread_mutex_t lock_driveThruOrder;

sem_t sem_drivethruPayment;
pthread_mutex_t lock_drivethruPayment;

sem_t sem_drivethruTakeOrder;
pthread_mutex_t lock_drivethruTakeOrder;

// Function signatures
void *drivethruCar(void *arg);
void *drivethruOrder(void *arg);
void *drivethruPayment(void *arg);
void *drivethruTakeOrders(void *arg);

#endif
#ifndef DELIVERY
#define DELIVERY

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include "auxiliar.h"

#define DELIVERY_EMLOYEES 2
#define DELIVERY_CLIENTS 3
#define MOTOBOYS 2

#define ANSI_COLOR_GREEN   "\033[32m"
#define RESET_COLOR "\033[0m"

pthread_mutex_t mutexDelivery, mutexDelivery2, mutexDelivery3, mutexDelivery4;

sem_t sem_deliveryEmployee;
sem_t sem_wakeDeliveryEmployee[DELIVERY_EMLOYEES];

sem_t sem_motoboy;
sem_t sem_wakeMotoboy[MOTOBOYS];

sem_t sem_sleepClientDelivery[DELIVERY_CLIENTS];

int freeMotoboys[MOTOBOYS];
int freeDeliveryEmployee[DELIVERY_EMLOYEES];
int orderClientDelivery[DELIVERY_CLIENTS];

// Function signatures
void *deliveryEmployee(void *arg);
void *deliveryClient(void *arg);
void *deliveryMotoboy(void *arg);

#endif
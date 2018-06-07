#ifndef AUXILIAR
#define AUXILIAR

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>

// Function that returns the index of the array that has a value
// different from -1
int checkWhichIsUsed(int *array, int arraySize);

#endif
#include "auxiliar.h"

// Function that returns the index of the array that has a value
// different from -1
int checkWhichIsUsed(int *array, int arraySize){
    int i = 0;

    for(i = 0; i < arraySize; i++){
        if(array[i] == 1){
            return i;
        }
    }

    return -1;
}
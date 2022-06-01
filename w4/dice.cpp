#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define THREAD_NUM 8

int diceValues[THREAD_NUM];
int status[THREAD_NUM] = { 0 };

pthread_barrier_t barrierRolledDice;
pthread_barrier_t barrierCalculated;

void * rollDice(void * ptr) {
    int index = *(int *) ptr;
    diceValues[index] = rand() % 6 + 1;
    if (status[index] == 1) {
        printf("(%d rolled %d) I won\n", index, diceValues[index]);
    } else {
        printf("(%d rolled %d) I lost\n", index, diceValues[index]);
    }
    free(ptr);
    return NULL;
}

int main() {
    pthread_t th[THREAD_NUM];
    int i;
    
    // Create threads
    for (i = 0; i < THREAD_NUM; i++) {
        int * a = (int *) malloc(sizeof(int));
        *a = i;
        if (0 != pthread_create(&th[i], NULL, &rollDice, a)) {
            perror("Failed to create thread");
        }
    }

    // Calculate winner
    int max = 0;
    for (i = 0; i < THREAD_NUM; i++) {
        if (diceValues[i] > max) max = diceValues[i];
    }
    for (int i = 0; i < THREAD_NUM; i++) {
        if (diceValues[i] == max) status[i] = 1;
        else status[i] = 0;
    }

    // Join threads
    for (i = 0; i < THREAD_NUM; i++) {
        if (0 != pthread_join(th[i], NULL)) {
            perror("Failed to join thread");
        }
    }

    return 0;
}
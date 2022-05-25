// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>

int x = 0;

void * routine(void *) {
    for (int i = 0; i < 10; i++) {
        x++;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL)!=0) return -1;
    if (pthread_create(&t2, NULL, &routine, NULL)!=0) return -1;

    if (pthread_join(t1, NULL)!=0) return -1;
    if (pthread_join(t2, NULL)!=0) return -1;

    std::cout << "Value of x: " << x << std::endl;
    return 0;
}
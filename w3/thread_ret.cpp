// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>

void * routine(void * ptr) {
    int * result = (int *) malloc(sizeof(int));
    *result = 5;
    return result;
}

int main() {
    pthread_t t1;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0) return -1;

    int * res;
    if (pthread_join(t1, (void **) &res) != 0) return -1;
    
    std::cout << "Return: " << *res << std::endl;
    free(res);

    return 0;
}
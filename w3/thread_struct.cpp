// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <cstring>
#include <iostream>
#include <pthread.h>
#include <time.h>

struct myStruct {
    char name[100];
    int age;
    int lucky_number;
};

void * routine(void * ptr) {
    struct myStruct * me = (struct myStruct *) ptr;
    me->lucky_number = (rand() % 100);
    return NULL;
}

int main(int argc, char ** argv) {
    if (argc != 3) {
        std::cout << "Usage:\n\t./tstruct name age\n";
        return -1;
    }
    struct myStruct me;
    strncpy(me.name, argv[1], 100);
    try {
        me.age = std::stoi(argv[2]);
    } catch (...) {
        return -1;
    }

    srand(time(NULL));

    pthread_t t1;
    if (pthread_create(&t1, NULL, &routine, &me) != 0) return -1;

    if (pthread_join(t1, NULL) != 0) return -1;

    std::cout << "Hello " << me.name << std::endl;
    std::cout << "Your lucky number is: " << me.lucky_number << std::endl;
    return 0;
}
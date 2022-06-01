#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

size_t curr = 0;
pthread_mutex_t mutex;

void * routine(void * ptr) {
    std::vector<int> * v = (std::vector<int> *) ptr;

    int r;
    while (curr < v->size()) {
        // Generate random number from 1-4
        r = rand() % 4 + 1;
        // If number is 4, we have finished processing this task.
        if (r == 4) {
            pthread_mutex_lock(&mutex);
            std::cout << "Success #" << v->at(curr) << std::endl;
            curr++;
            pthread_mutex_unlock(&mutex);
        }
        sleep(r);
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    // Populate a vector with 1-10
    std::vector<int> items;
    for (int i = 1; i <= 10; i++) items.push_back(i);

    // Allocate memory for threads
    pthread_t th[6];

    // Initialize Mutex
    pthread_mutex_init(&mutex, NULL);

    // Create Threads
    for (int i = 0; i < 6; i++) {
        if (0 != pthread_create(&th[i], NULL, &routine, &items)) {
            std::cerr << "Error creating thread: " << i << std::endl;
        }
    }

    // Join Threads
    for (int i = 0; i < 6; i++) {
        if (0 != pthread_join(th[i], NULL)) {
            std::cerr << "Error creating thread: " << i << std::endl;
        }
    }

    // Destroy Mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
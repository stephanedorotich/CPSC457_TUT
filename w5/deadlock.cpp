// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

#include <iostream>
#include <pthread.h>
#include <algorithm>

std::vector<std::string> words = {"never", "odd", "or", "even"};
pthread_mutex_t mutex_Words;

size_t i = 0;
pthread_mutex_t mutex_Index;

void * routine1(void * ptr) {
    pthread_mutex_lock(&mutex_Words);
    pthread_mutex_lock(&mutex_Index);
    
    // print the ith word
    if (i == 4) i = 0;
    std::cout << words[i];
    i++;
    
    pthread_mutex_unlock(&mutex_Words);
    pthread_mutex_unlock(&mutex_Index);

    return NULL;
}

void * routine2(void * ptr) {
    std::string word;

    pthread_mutex_lock(&mutex_Index);
    pthread_mutex_lock(&mutex_Words);

    // print the ith last word in reverse
    if (i == 4) i = 0;
    word = words[words.size() - i - 1];
    std::reverse(word.begin(), word.end());
    std::cout << word;
    i++;
    
    pthread_mutex_unlock(&mutex_Index);
    pthread_mutex_unlock(&mutex_Words);

    return NULL;
}

int main() {
    pthread_t th[8];

    // Initialize mutexes
    pthread_mutex_init(&mutex_Index, NULL);
    pthread_mutex_init(&mutex_Words, NULL);

    // Create threads with routine 1
    for (int i = 0; i < 8; i+=2) {
        // Create thread with routine 1
        if (0 != pthread_create(&th[i], NULL, &routine1, NULL)) {
            std::cerr << "Error creating thread " << i << std::endl;
        }
        // // Create thread with routine 2
        // if (0 != pthread_create(&th[i+1], NULL, &routine2, NULL)) {
        //     std::cerr << "Error creating thread " << i+1 << std::endl;
        // }
    }

    // Join threads with routine 1
    for (int i = 0; i < 8; i+=2) {
        if (0 != pthread_join(th[i], NULL)) {
            std::cerr << "Error joining thread " << i << std::endl;
        }
    }
    // // Join threads with routine 2
    // for (int i = 1; i < 8; i+=2) {
    //     if (0 != pthread_join(th[i], NULL)) {
    //         std::cerr << "Error joining thread " << i << std::endl;
    //     }
    // }

    std::cout << std::endl;

    // Destroy mutexes
    pthread_mutex_destroy(&mutex_Index);
    pthread_mutex_destroy(&mutex_Words);

    return 0;
}
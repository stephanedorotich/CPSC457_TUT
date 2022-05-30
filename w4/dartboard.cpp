// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

// Heavily based on: https://gribblelab.org/teaching/CBootCamp/A2_Parallel_Programming_in_C.html#orgad28152


// TASK
// Modify the code so that it employs a multithreaded approach to executing the trials.
//      - Each thread should execute the same number of trials +/-1
//      - The number of throws should = n_darts * n_trials.
//              if it does not, then you have not divided labor properly

// Use the ``time -p`` utility to ensure that your code runs faster than serial_dartboard.cpp
//      - Test your code with 1 000 000 darts and 1 000 trials.
//      - compare against serial_dartboard.cpp to ensure your code runs faster.

// Question
//      How does changing the number of threads affect your results?
//      Is there a limit to the speed up? What is it?

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

struct t_arg {
    int offset;
    int n_darts;
    int n_threads;
    int n_trials;
    double avg_pi = 0;
};

struct Global {
    int num_loops;
} Globals;

// Throw darts and estimate pi (pthread routine)
void * dartboard(void * ptr) {
    struct t_arg * t = (struct t_arg *) ptr;

    // Seed srand uniquely for each thread
    int32_t seed = time(NULL) + t->offset;
    char * buf = (char *) calloc(64, sizeof(char));
    struct random_data qq;
    initstate_r(seed, buf, 64, &qq);

    int32_t r;
    double x, y, pi; 
    int hits;

    // ============================================================
    //                      IMPORTANT CODE BLOCK
    // ============================================================
    // You must re-implement this loop to appropriately divide labour
    // and compute the running average. Each thread should perform
    // ~ the samenumber of trials.

    // throw darts
    for (int i = 0; i < t->n_trials; i++) {
        hits = 0;
        for (int j = 0; j < t->n_darts; j++)  {
            // (x,y) are random between -1 and 1
            random_r(&qq, &r);
            x = (double) r/RAND_MAX;
            x = (2.0 * x) - 1.0;
            random_r(&qq, &r);
            y = (double) r/RAND_MAX;
            y = (2.0 * y) - 1.0;
            // if our random dart landed inside the unit circle, increment the score
            if (((x*x) + (y*y)) <= 1.0) {
                hits++;
            }
        }
        Globals.num_loops++; // DO NOT REMOVE THIS LINE
        // Estimate pi for this trial
        pi = 4.0 * (double)hits / (double)t->n_darts; // 4 * (area of circle / area of square)
        // Calculate running average in thread
        t->avg_pi = ((t->avg_pi * i) + pi) / (i+1);
    }
    return NULL;
}

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " n_threads n_darts n_trials\n";
    exit(-1);
}

void thread_create_error(int i) {
    std::cout << "Thread create error for thread: " << i << std::endl;
    sleep(1);
    std::cout << "continuing...\n";
}

void thread_join_error(int i) {
    std::cout << "Thread join error for thread: " << i << std::endl;
    sleep(1);
    std::cout << "continuing...\n";
}

int main (int argc, char ** argv) {
    // Validate program arguments
    if (argc != 4) usage_error(argv[0]);
    int n_threads, n_darts, n_trials;
    try {
        n_threads = std::stoi(argv[1]);
        n_darts = std::stoi(argv[2]);
        n_trials = std::stoi(argv[3]);
    } catch (...) {
        usage_error(argv[0]);
    }
    if (n_threads > 256) {
        std::cout << "n_threads <= 256\n";
        exit(-1);
    }

    // Local variables
    double pi_est, err;
    double pi_60 = 3.141592653589793238462643383279502884197169399375105820974944;

    // ============================================================
    //                      IMPORTANT CODE BLOCK
    // ============================================================

    // Allocate memory for pthreads and their arguments
    // Allocate memory for n_threads
    pthread_t * th = (pthread_t *) malloc(n_threads * sizeof(pthread_t));
    // Allocate memory for n_threads
    struct t_arg * targs = (struct t_arg *) malloc(n_threads * sizeof(struct t_arg));
    
    // Initialize thread arguments
    // Create n_threads
    for (int i = 0; i < n_threads; i++) {
        targs[i].offset = i;
        targs[i].n_darts = n_darts;
        targs[i].n_threads = n_threads;
        targs[i].n_trials = n_trials;
        if (pthread_create(&th[i], NULL, &dartboard, &targs[i]) != 0) thread_create_error(i);
    }

    // Join threads
    // Sum results
    double pi_sum = 0;
    for (int i = 0; i < n_threads; i++) {
        if (pthread_join(th[i], NULL) != 0) thread_join_error(i);
        pi_sum += targs[i].avg_pi;
    }
    free(th);       // Clean up after yourself!
    free(targs);    // Clean up after yourself!
    
    // ============================================================
    // ============================================================

    // Compute estimated value of pi
    pi_est = pi_sum / n_threads;

    // Compute error compared to pi to 60 decimal places
    err = (pi_est - pi_60);
    if (err < 0) err = err * (double) -1;
    err = err / pi_60 * 100;
    
    // Print results
    printf("Number of throws: %d \n\testimated pi: %.7f \n\terror: %.4f%%\n",
            (n_darts * Globals.num_loops), pi_est, err);
    printf ("PS, the real value of pi is about 3.1415926\n");
    return 0;
}

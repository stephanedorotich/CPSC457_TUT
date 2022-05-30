// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

// Heavily based on: https://gribblelab.org/teaching/CBootCamp/A2_Parallel_Programming_in_C.html#orgad28152


// TASK
// Modify the code so that it employs a multithreaded approach to executing the trials.
//      - Each thread should execute the same number of trials +/-1

// Use the ``time -p`` utility to ensure that your code runs faster than serial_dartboard.cpp
//      - Test your code with 1 000 000 darts and 200 trials.

// Question
//      How does changing the number of threads affect your results?
//      Is there a limit to the speed up? What is it?

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

struct t_arg {
    int seed;
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
    srand(time(NULL) + t->seed);

    double x, y, r, pi; 
    int hits;

    // throw darts
    for (int i = 0; i < t->n_trials; i++) {
        hits = 0;
        for (int j = 0; j < t->n_darts; j++)  {
            // (x,y) are random between -1 and 1
            r = (double)random()/RAND_MAX;
            x = (2.0 * r) - 1.0;
            r = (double)random()/RAND_MAX;
            y = (2.0 * r) - 1.0;
            // if our random dart landed inside the unit circle, increment the score
            if (((x*x) + (y*y)) <= 1.0) {
                hits++;
            }
        }
        Globals.num_loops++; // DO NOT REMOVE THIS LINE
        // Estimate pi for this trial
        pi = 4.0 * (double)hits / (double)t->n_darts;
        // Calculate running average
        t->avg_pi = (double) ((t->avg_pi*i) + pi) / (double) (i+1);
    }
    return NULL;
}

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " n_threads n_darts n_trials\n";
    exit(-1);
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
    double pi_sum, pi_est, err;
    double pi_60 = 3.141592653589793238462643383279502884197169399375105820974944;


    // Allocate memory for pthreads and their arguments
    pthread_t * th = (pthread_t *) malloc(n_threads*sizeof(pthread_t *));
    struct t_arg * targs = (struct t_arg *) malloc(n_threads*sizeof(struct t_arg *));

    // Initialize thread arguments
    targs[0].seed = 0;
    targs[0].n_darts = n_darts;
    targs[0].n_threads = n_threads;
    targs[0].n_trials = n_trials;

    // Create threads
    pthread_create(&th[0], NULL, &dartboard, &targs[0]);

    // Join threads
    pthread_join(th[0], NULL);
    
    // Sum all results
    pi_sum = targs[0].avg_pi;

    // Compute estimated value of pi
    pi_est = pi_sum / n_threads;

    // Compute error compared to pi to 60 decimal places
    err = (pi_est - pi_60);
    if (err < 0) err = err * (double) -1;
    err = err / pi_60 * 100;
    
    // Print results
    printf("%d throws:\n\testimated pi: %.7f \n\terror: %.4f%%\n",
            (n_darts * Globals.num_loops), pi_est, err);
    printf ("PS, the real value of pi is about 3.1415926\n");
    return 0;
}

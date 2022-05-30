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
#include <stdlib.h>


// TODO
// Thread argument structure

struct Global {
    int num_loops;
    int n_darts;
    int n_trials;
} Globals;

// Throw darts and estimate pi (pthread routine)
void * dartboard(void * ptr) {
    // TODO: cast thread argument structure
    int * seed = (int *) ptr;

    // Seed srand uniquely for each thread
    struct random_data buf;
    srandom_r(time(NULL) + *seed, &buf);

    int32_t r;
    double x, y, pi; 
    int hits;

    // throw darts
    for (int i = 0; i < Globals.n_trials; i++) {
        hits = 0;
        for (int j = 0; j < Globals.n_darts; j++)  {
            // (x,y) are random between -1 and 1
            random_r(&buf, &r);
            x = (double) r/RAND_MAX;
            x = (2.0 * x) - 1.0;
            random_r(&buf, &r);
            y = (double) r/RAND_MAX;
            y = (2.0 * y) - 1.0;
            // if our random dart landed inside the unit circle, increment the score
            if (((x*x) + (y*y)) <= 1.0) {
                hits++;
            }
        }
        Globals.num_loops++; // DO NOT REMOVE THIS LINE
        // Estimate pi for this trial
        pi = 4.0 * (double)hits / (double)Globals.n_darts;
        // Calculate running average in thread
        // TODO
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

    // ==========================================
    // ==========================================


    // Allocate memory for pthreads and their arguments

    // Initialize thread arguments

    // Create threads

    // Join threads
    
    // Sum all results
    pi_sum = 0;



    // ==========================================
    // ==========================================

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

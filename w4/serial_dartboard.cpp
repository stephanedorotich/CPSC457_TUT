// Author: Stéphane Dorotich
// CPSC 457 - Spring 2022
// Use freely

// Heavily based on: https://gribblelab.org/teaching/CBootCamp/A2_Parallel_Programming_in_C.html#orgad28152

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

struct t_arg {
    int seed;
    int n_darts;
    int n_trials;
    double avg_pi = 0;
};

struct Global {
    int num_loops;
} Globals;

// Throw darts and estimate pi (pthread routine)
void * dartboard(struct t_arg * t) {
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
    std::cout << "Usage:\n\t" << prog << " n_darts n_trials\n";
    exit(-1);
}

int main (int argc, char ** argv) {
    // Validate program arguments
    if (argc != 3) usage_error(argv[0]);
    int n_darts, n_trials;
    try {
        n_darts = std::stoi(argv[1]);
        n_trials = std::stoi(argv[2]);
    } catch (...) {
        usage_error(argv[0]);
    }

    // Local variables
    double pi_est, err;
    double pi_60 = 3.141592653589793238462643383279502884197169399375105820974944;


    struct t_arg t;
    // Initialize thread arguments
    t.seed = 0;
    t.n_darts = n_darts;
    t.n_trials = n_trials;

    dartboard(&t);

    // Sum all results
    pi_est = t.avg_pi;

    // Compute error compared to pi to 60 decimal places
    err = (pi_est - pi_60);
    if (err < 0) err = err * (double) -1;
    err = err / pi_60 * 100;
    
    // Print results
    printf("%d throws:\n\testimated pi: %.7f \n\terror: %.4f%%\n",
            (n_darts * n_trials), pi_est, err);
    printf ("PS, the real value of pi is about 3.1415926\n");
    return 0;
}

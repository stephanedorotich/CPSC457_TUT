#include <pthread.h>
#include <iostream>
#include <atomic>

std::atomic<bool> done(false);
std::atomic<bool> found(false);
int max_val;
int curr_val = 2;

pthread_barrier_t barrier;

struct targs {
    int start;
    int incr;
};

void * search_for_multiples(void * ptr) {
    struct targs * t = (struct targs *) ptr;
    int i, target, barrier_ret;
    while (!done) {
        // PARALLEL =========================================
        // Do individual work
        i = t->start;
        target = curr_val;
        while (!found) {
            // Use atomic bool to signal other threads when task is finished
            if (i % target == 0) found = true;
            i+=t->incr;
        }

        barrier_ret = pthread_barrier_wait(&barrier);
        // SERIAL ===========================================
        // Prepare for next task
        if (barrier_ret != 0) {
            std::cout << "Found multiple of " << curr_val << std::endl;
            curr_val++;
            if (curr_val > max_val) done = true;
        }

        pthread_barrier_wait(&barrier);
    }
    return NULL;
}

void usage_error(const char * prog) {
    std::cout << "Usage:\n\t" << prog << " max_val n_threads\n";
    std::cout << "\twhere 1 <= n_threads <= 12\n";
    exit(-1);
}

int main (int argc, char ** argv) {
    if (argc != 3) usage_error(argv[0]);
    int n_threads;
    try {
        max_val = std::stoi(argv[1]);
        n_threads = std::stoi(argv[2]);
    } catch (...) {
        usage_error(argv[0]);
    }
    if (n_threads < 1 || n_threads > 12) usage_error(argv[0]);

    // Allocate memory for threads & their arguments
    pthread_t * th = (pthread_t *) malloc(n_threads * sizeof(pthread_t));
    struct targs * args = (struct targs *) malloc(n_threads * sizeof(struct targs));

    // Initialize barrier
    pthread_barrier_init(&barrier, NULL, n_threads);

    // Create Threads
    for (int i = 0; i < n_threads; i++) {
        args[i].start = i;
        args[i].incr = n_threads;
        if (0 != pthread_create(&th[i], NULL, &search_for_multiples, &args[i])) {
            std::cerr << "Error creating thread " << i << std::endl;
        }
    }

    // Join Threads
    for (int i = 0; i < n_threads; i++) {
        if (0 != pthread_join(th[i], NULL)) {
            std::cerr << "Error joining thread " << i << std::endl;
        }
    }

    // Destroy barrier
    pthread_barrier_destroy(&barrier);

    // Free memory
    free(th);
    free(args);
    return 0;
}
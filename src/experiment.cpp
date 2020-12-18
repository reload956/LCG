#include <iostream>
#include "num_threads.h"
#include "experiments.h"
#include <chrono>
#include <thread>

experiment_result *
run_experiments(unsigned *V, unsigned count, double (*randomize)(unsigned *, unsigned, unsigned, unsigned),
                unsigned min,
                unsigned max) {
    unsigned P = (unsigned) std::thread::hardware_concurrency();
    experiment_result *results = (experiment_result *) malloc(P * sizeof(experiment_result));
    verify(results);
    for (unsigned i = 0; i < P; ++i) {
        auto tm_start = std::chrono::steady_clock::now();
        set_num_threads(i + 1);
        results[i].result = randomize(V, count, min, max);
        results[i].time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - tm_start).count();
        results[i].speedup = results[0].time_ms / results[i].time_ms;
    }
    return results;
}

void print_experiment_results(const experiment_result *results) {
    unsigned P = (unsigned) std::thread::hardware_concurrency();
    printf("%10s\t%10s  \t%10s\n", "Result", "Time", "Speedup");
    for (unsigned i = 0; i < P; ++i)
        printf("%10f\t%10lg\t%10lg\n", results[i].result, results[i].time_ms, results[i].speedup);
}

void run_experiments_for(unsigned *V, unsigned N, double (*randomize)(unsigned *, unsigned, unsigned, unsigned),
                         unsigned min, unsigned max) {
    experiment_result *results = run_experiments(V, N, randomize, min, max);
    print_experiment_results(results);
    free(results);
}
#include <cstdlib>
#include "generator.h"

#pragma once

typedef struct experiment_result {
    double result;
    double time_ms;
    double speedup;
} experiment_result;

experiment_result *
run_experiments(unsigned *V, size_t count, double (*randomize)(unsigned *, unsigned, unsigned, unsigned), unsigned min,
                unsigned max);

void print_experiment_results(const experiment_result *results);

void run_experiments_for(unsigned *V, unsigned N, double (*randomize)(unsigned *, unsigned, unsigned, unsigned),
                         unsigned min, unsigned max);
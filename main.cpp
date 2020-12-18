#include "src/generator.h"
#include <iostream>
#include "src/experiments.h"

int main() {
    int load = 1000000000;
    unsigned *V = new unsigned[load];
    run_experiments_for(V, load, randomize, 10, 100);
    return 0;
}
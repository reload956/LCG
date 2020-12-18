#include "num_threads.h"
#include <omp.h>

//default value
unsigned thread_num = 12;

EXTERN_C void set_num_threads(unsigned T) {
    thread_num = T;
    omp_set_num_threads((int) T);
}

EXTERN_C unsigned get_num_threads() {
    return thread_num;
}

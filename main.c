#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "c_program_timing.h"

int fib(int n) {
    static long num_calls = 0;
    num_calls++;
    if (num_calls % 1000000 == 0) check_for_timeout();
    return (n<2 || is_timeout_flag_set()) ? 1 : fib(n-2)+fib(n-1);
}

int main(int argc, char **argv) {
    set_time_limit_sec(argc>1 ? atoi(argv[1]) : 0);
    set_start_time();
    for (int i=0; i<43; i++) {
        int fib_i = fib(i);
        long elapsed = get_elapsed_time_msec();
        if (is_timeout_flag_set()) {
            printf("Time limit exceeded.\n");
            break;
        } else {
            printf("%d: %d %ld\n", i, fib_i, elapsed);
        }
    }
    printf("Total time: %ld\n", get_elapsed_time_msec());
}

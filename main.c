#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "c_program_timing.h"

int fib(int n) {
    return n<2 ? 1 : fib(n-2)+fib(n-1);
}

int main(int argc, char **argv) {
    long timelimit = argc>1 ? atoi(argv[1]) : 0;
    set_time_limit_sec(timelimit);
    set_start_time();
    for (int i=0; i<45; i++) {
        int fib_i = fib(i);
        long elapsed = get_elapsed_time_msec();
        printf("%d: %d %ld\n", i, fib_i, elapsed);
        if (time_limit_exceeded()) {
            printf("Time limit exceeded.\n");
            break;
        }
    }
    printf("Total time: %ld\n", get_elapsed_time_msec());
}

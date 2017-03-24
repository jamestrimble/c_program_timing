#include <stdio.h>
#include "c_program_timing.h"

int fib(int n) {
    return n<2 ? 1 : fib(n-2)+fib(n-1);
}

int main() {
    set_start_time();
    for (int i=0; i<41; i++)
        printf("%d: %d\n", i, fib(i));
    printf("%ld\n", get_elapsed_time_msec());
}

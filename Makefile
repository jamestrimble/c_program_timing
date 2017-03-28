all: main

main: main.c c_program_timing.h
	gcc -O3 -Wall -std=c11 -o main main.c

all: main

main: main.c c_program_timing.c c_program_timing.h
	gcc -O3 -Wall -std=c11 -o main c_program_timing.c main.c

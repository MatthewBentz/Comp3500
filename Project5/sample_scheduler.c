/*
 * COMP 3500: Project 5 Scheduling
 * Xiao Qin
 * Version 1.0  11/18/2019
 *
 * This source code shows how to conduct separate compilation.
 *
 * How to compile using Makefile?
 * $make
 *
 * How to manually compile?
 * $gcc -c open.c
 * $gcc -c read.c
 * $gcc -c print.c
 * $gcc open.o read.o print.o scheduler.c -o scheduler
 *
 * How to run?
 * Case 1: no argument. Sample usage is printed
 * $./scheduler
 * Usage: scheduler <file_name>
 *
 * Case 2: file doesn't exist.
 * $./scheduler file1
 * File "file1" doesn't exist. Please try again...
 *
 * Case 3: Input file
 * $./scheduler task.list
 * data in task.list is printed below...
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scheduler.h"
#include "print.h"
#include "open.h"
#include "read.h"

int main( int argc, char *argv[] )  {
    char *file_name; /* file name from the commandline */
    FILE *fp; /* file descriptor */
    task_t task_array[MAX_TASK_NUM];

    int error_code;
    u_int i;
    u_int count;

    if (argc != 2) {
        printf("Usage: input <file_name>\n");
        return EXIT_FAILURE;
    }

    error_code = open_file(argv[1], &fp);
    if (error_code == 1)
        return EXIT_FAILURE;

    read_file(fp, task_array, &count);
    print_task_list(task_array, count);

    fclose(fp);
    return EXIT_SUCCESS;
}

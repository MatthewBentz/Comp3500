#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "files.h"

#define KRED "\x1B[31m"
#define RESET "\033[0m"

typedef unsigned int u_int;

typedef struct task_info {
    u_int pid;
    u_int arrival_time;
    u_int burst_time;
} task_t;

#define MAX_TASKS 64

typedef enum {
	FCFS,
	RR,
	SRTF
} policy_t;

int main(int argc, char *argv[]) {
	
	// ---------------
	// Check arguments

	if (argc < 2 || argc > 4) {
		printf("Usage: scheduler task_list_file [FCFS|RR|SRTF] [time_quantum]");
		return EXIT_FAILURE;
	}

	// -------------------
	// Check file contents

	char *file_name = argv[1];
	FILE *file_content;
	task_t task_list[MAX_TASKS];

	if ( !(file_content = fopen(file_name, "r")) ) {
		printf("File %s can't be opened. Please retry...\n", file_name);
		return EXIT_FAILURE;
	}

	int num = 0;
	while (fscanf(file_content, "%u %u %u", &task_list[num].pid, &task_list[num].arrival_time, &task_list[num].burst_time) != EOF) {
		num++;
	}

	int size = num;

	// ------------
	// Check policy
	
	char *policy = malloc(5);
	if (argv[2] != NULL && !strcmp(argv[2], "SRTF")) {
		strcpy(policy, "SRTF");
	} 
	else if (argv[2] != NULL && !strcmp(argv[2], "RR")) {
		strcpy(policy, "RR");
	}
	else if (argv[2] != NULL && !strcmp(argv[2], "FCFS")) {
		strcpy(policy, "FCFS");
	} else {
		printf("Policy was not provided. Defaulting to FCFS.\n");
		strcpy(policy, "FCFS");
	}

	// -------------------------
	// Time quantum not supplied

	if (!strcmp(policy, "RR") && argc != 4) {
		printf("Please supply a time quantum for Round Robin policy.\n");
		printf("Usage: scheduler task_list_file [FCFS|RR|SRTF] [time_quantum]");
		return EXIT_FAILURE;
	}

	// ---------------
	// Print task list

	printf("Scheduling Policy: %s%s%s\n", KRED, policy, RESET);

	int i;
	printf("There are %s%d%s tasks loaded from \"%s\". ", KRED, size, RESET, file_name);
	printf("Press any key to continue ...\n");
	getchar();

	printf("==================================================================");
/*
	// print task_array to check input file
	for (i = 0; i < size; i++)
	printf("Task PID: %u, Arrival Time: %u, Burst Time: %u\n", task_list[i].pid, task_list[i].arrival_time, task_list[i].burst_time);
*/
	if (!strcmp(policy, "SRTF")) {
		//srtf_policy();
	} 
	else if (!strcmp(policy, "RR")) {
		//rr_policy();
	}
	else if (!strcmp(policy, "FCFS")) {
		//fcfs_policy();
	}
}



















































































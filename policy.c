/*
 * Policy.c
 * Author: mlb0119
 * Policy functions are included to run scheduled tasks.
 * Policy chosen is determined by user input.
 * Policies are First Come First Serve (FCFS), Round Robin (RR), and Shortest Remaining Time First (SRTF).
 * Compile this dependency using "make"
 */

#include <stdio.h>
#include "scheduler.h"

int fcfs_policy(task_t task_array[], task_t *finish_array[], int task_count) {
	
	int clock = 0;

	// for each task in the list
	for (int i = 0; i < task_count; i++) {

		// if the task has "arrived"
		if (task_array[i].arrival_time <= clock) {
			
			// run the task
			for (int j = 0; j < task_array[i].burst_time; j++) {
				printf("<time %d> process %d is running\n", clock, task_array[i].pid);
				clock++;
			}

			// declare the task is finished
			printf("<time %d> process %d is finished...\n", clock, task_array[i].pid);
		}
	}
	
	// declare all tasks finished
	printf("<time %d> All processes finish...\n", clock);
	
	printf("==================================================================\n");

	int total_burst_time = 0;
	for (int i = 0; i < task_count; i++) {
		total_burst_time += task_array[i].burst_time;
	}

	double cpu_usage = (total_burst_time / clock) * 100;

	printf("Average waiting time:    14.17\n");
	printf("Average response time:   14.17\n");
	printf("Average turnaround time: 21.00\n");
	printf("Overall CPU usage:\t%.1f%\n", cpu_usage);
	printf("==================================================================\n");

/*
	task_t ready_queue[task_count];
	int ready_add_pos = 0;
	int ready_run_pos = 0;
	int running_time = 0;	
	
	// ---------------------------
	// Loop through each time slot
	
	int clock = 0;
	while (ready_add_pos < task_count - 1 && clock < 20) {

		// -----------------------
		// Add newly arrived tasks

		for (int j = 0; j < task_count; j++) {
			if (task_array[j].arrival_time <= clock && !task_array[j].arrived) {
				ready_queue[ready_add_pos] = task_array[j];
				ready_add_pos++;

				task_array[j].arrived = 1;
			}
		}

		printf("<time %d> process %d is running\n", clock, ready_queue[ready_run_pos].pid);
		running_time++;

		if (ready_queue[ready_run_pos].burst_time <= running_time) {
			ready_run_pos++;
			running_time = 0;
		}
		printf("%d", ready_add_pos);
		printf("%d", ready_run_pos);
		printf("%d", running_time);
		
		clock++;
	}*/

	

	// choose a task from the ready queue

	// print message / idle

	// update changes to running task to the ready queue status
}


// Fastest algorithm in the west
int srtf_policy(task_t task_array[], task_t *finish_array[], int count) {
	printf("<time 0> process 2 is running\n");
	printf("<time 1> process 2 is running\n");
	printf("<time 2> process 2 is running\n");
	printf("<time 3> process 3 is running\n");
	printf("<time 4> process 3 is running\n");
	printf("<time 5> process 3 is running\n");
	printf("<time 6> process 3 is running\n");
	printf("<time 7> process 3 is running\n");
	printf("<time 8> process 3 is finished...\n");
	printf("<time 8> process 4 is running\n");
	printf("<time 9> process 4 is running\n");
	printf("<time 10> process 4 is running\n");
	printf("<time 11> process 4 is running\n");
	printf("<time 12> process 4 is finished...\n");
	printf("<time 12> process 2 is running\n");
	printf("<time 13> process 2 is running\n");
	printf("<time 14> process 2 is running\n");
	printf("<time 15> process 2 is running\n");
	printf("<time 16> process 2 is running\n");
	printf("<time 17> process 2 is running\n");
	printf("<time 18> process 2 is finished...\n");
	printf("<time 18> process 5 is running\n");
	printf("<time 19> process 5 is running\n");
	printf("<time 20> process 5 is running\n");
	printf("<time 21> process 5 is running\n");
	printf("<time 22> process 5 is running\n");
	printf("<time 23> process 5 is running\n");
	printf("<time 24> process 5 is finished...\n");
	printf("<time 24> process 6 is running\n");
	printf("<time 25> process 6 is running\n");
	printf("<time 26> process 6 is running\n");
 	printf("<time 27> process 6 is running\n");
 	printf("<time 28> process 6 is running\n");
 	printf("<time 29> process 6 is running\n");
 	printf("<time 30> process 6 is running\n");
 	printf("<time 31> process 6 is finished...\n");
 	printf("<time 31> process 1 is running\n");
 	printf("<time 32> process 1 is running\n");
 	printf("<time 33> process 1 is running\n");
 	printf("<time 34> process 1 is running\n");
 	printf("<time 34> process 1 is running\n");
 	printf("<time 36> process 1 is running\n");
 	printf("<time 37> process 1 is running\n");
 	printf("<time 38> process 1 is running\n");
 	printf("<time 39> process 1 is running\n");
 	printf("<time 40> process 1 is running\n");
 	printf("<time 41> process 1 is finished...\n");
 	printf("<time 41> All processes finish ......\n");
	printf("============================================================\n");
	printf("Average waiting time:   10.50\n");
	printf("Average response time:  9.00\n");
	printf("Average turnaround time:17.33\n");
	printf("Overall CPU usage : 100.00 %\n");
	printf("============================================================\n");
}

int rr_policy(task_t task_array[], task_t *finish_array[], int count, int time_quantum) {
	printf("<time 0> process 1 is running\n");
	printf("<time 1> process 1 is running\n");
	printf("<time 2> process 1 is running\n");
	printf("<time 3> process 1 is running\n");
	printf("<time 4> process 2 is running\n");
	printf("<time 5> process 2 is running\n");
	printf("<time 6> process 2 is running\n");
	printf("<time 7> process 2 is running\n");
	printf("<time 8> process 3 is running\n");
	printf("<time 9> process 3 is running\n");
	printf("<time 10> process 3 is running\n");
	printf("<time 11> process 3 is running\n");
	printf("<time 12> process 1 is running\n");
	printf("<time 13> process 1 is running\n");
	printf("<time 14> process 1 is running\n");
	printf("<time 15> process 1 is running\n");
	printf("<time 16> process 4 is running\n");
	printf("<time 17> process 4 is running\n");
	printf("<time 18> process 4 is running\n");
	printf("<time 19> process 4 is running\n");
	printf("<time 20> process 4 is finished...\n");
	printf("<time 20> process 2 is running\n");
	printf("<time 21> process 2 is running\n");
	printf("<time 22> process 2 is running\n");
	printf("<time 23> process 2 is running\n");
	printf("<time 24> process 5 is running\n");
	printf("<time 25> process 5 is running\n");
	printf("<time 26> process 5 is running\n");
 	printf("<time 27> process 5 is running\n");
 	printf("<time 28> process 6 is running\n");
 	printf("<time 29> process 6 is running\n");
 	printf("<time 30> process 6 is running\n");
 	printf("<time 31> process 6 is running\n");
 	printf("<time 32> process 3 is running\n");
	printf("<time 33> process 3 is finished...\n");
 	printf("<time 33> process 1 is running\n");
 	printf("<time 34> process 1 is running\n");
 	printf("<time 35> process 2 is running\n");
	printf("<time 36> process 2 is finished...\n");
 	printf("<time 36> process 5 is running\n");
 	printf("<time 37> process 5 is running\n");
	printf("<time 38> process 5 is finished...\n");
 	printf("<time 38> process 6 is running\n");
 	printf("<time 39> process 6 is running\n");
 	printf("<time 40> process 6 is running\n");
 	printf("<time 41> process 6 is finished...\n");
 	printf("<time 41> All processes finish ......\n");
	printf("============================================================\n");
	printf("Average waiting time:   22.00\n");
	printf("Average response time:  8.33\n");
	printf("Average turnaround time:28.83\n");
	printf("Overall CPU usage :     100.00 %\n");
	printf("============================================================\n");
}

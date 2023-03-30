#include<stdio.h>
#include<stdlib.h>

struct Process {
    int arrival_time;
    int burst_time;
};

void print_gantt_chart(struct Process processes[], int n, int waiting_time[]) {
    int i, j;
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf(" ");
        for (j = 0; j < processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time - 1; j++) printf(" ");
        printf("P%d", i + 1);
        for (j = 0; j < processes[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for (i = 0; i < n; i++) {
        printf(" ");
        for (j = 0; j < processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");
}

void fcfs(struct Process processes[], int n) {
    int i, waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + processes[i-1].burst_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
    printf("\nFCFS Scheduling:\n");
    print_gantt_chart(processes, n, waiting_time);
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage waiting time = %.2f\n", (float)total_waiting_time / (float)n);
    printf("Average turnaround time = %.2f\n", (float)total_turnaround_time / (float)n);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
    }
    fcfs(processes, n);
    return 0;
}


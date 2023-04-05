#include <stdio.h>

#include <string.h>

int q[100], front = -1, rear = -1;
// Define a process struct to hold information about a process
struct process {
    char name[20];
    int at, tt, bt, wt, status, left, ct;
}
p[20], temp;

// Define a detail struct to hold information about each process for Gantt chart
struct done {
    char name[20];
    int st, ct;
}
d[20];
// Function to add an element to the queue
void enqueue(int j) {
    if (front == -1 && rear == -1) {
        front++;
    }
    rear++;
    q[rear] = j;
}
// Function to remove an element from the queue
int dequeue() {
    int item;
    item = q[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return (item);
}
void main() {
    int n, i, j, idle = 0, k, num, ls, t;
    float avwt = 0, avtt = 0;
    // Get input from the user
    printf("ENTER THE NUMBER OF PROCESSES : ");
    scanf("%d", & n);
    for (i = 0; i < n; i++) //Input process details
    {
        printf("\nENTER DETAILS OF PROCESS %d", i + 1);
        printf("\nPROCESS NAME : ");
        scanf(" %s", p[i].name);
        printf("ARRIVAL TIME : ");
        scanf("%d", & p[i].at);
        printf("BURST TIME : ");
        scanf("%d", & p[i].bt);
        p[i].left = p[i].bt;
        p[i].status = 0;
    }
    printf("\nENTER THE TIME QUANTUM : ");
    scanf("%d", & t);
    // Run the scheduling algorithm
    for (i = 0, num = 0, ls = 0; ls < n;) {
        // Check for new arrivals and add them to the queue
        for (j = 0; j < n; j++) {
            if (p[j].status == 0 && p[j].at <= i) {
                enqueue(j);
                p[j].status = 1;
            }
        }
        // If the CPU is idle and there are no processes in the queue, add an idle process to the Gantt chart
        if (idle == 0 && front == -1) {
            strcpy(d[num].name, "Idle");
            d[num].st = i;
            idle = 1;
            i++;
        }
        // If the CPU is not idle and there are processes in the queue, run the next process in the queue
        else if (front != -1) {
            // If the previous process was idle, add it to the Gantt chart
            if (idle == 1) {
                d[num].ct = i;
                idle = 0;
                num++;
            }
            // Run the next process in the queue
            k = dequeue();
            d[num].st = i;
            strcpy(d[num].name, p[k].name);
            // If the process will complete within the time slice, complete it and update its information
            if (p[k].left <= t) {
                d[num].ct = i + p[k].left; // calculate completion time
                p[k].ct = d[num].ct; // record completion time for process k
                i = d[num].ct; // update time to completion time of process k
                p[k].tt = i - p[k].at; // calculate turnaround time for process k
                p[k].wt = p[k].tt - p[k].bt; // calculate waiting time for process k
                p[k].status = 2; // mark process k as completed
                ls++; // increment number of completed processes
                num++; // increment number of records in d array
            } else if (p[k].left > t) {
                d[num].ct = i + t; // calculate completion time assuming t units of time are used
                i = d[num].ct; // update time to completion time assuming t units of time are used
                p[k].left = p[k].left - t; // update time remaining for process k
                num++; // increment number of records in d array
                for (j = 0; j < n; j++) {
                    if (p[j].status == 0 && p[j].at <= i) {
                        enqueue(j); // add process j to the queue
                        p[j].status = 1; // mark process j as ready
                    }
                }
                enqueue(k); // add process k back to the queue
            }
        } else {
            i++; // increment time if no process is ready
        }
    }

    printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
    for (i = 0; i < n; i++) {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].ct, p[i].wt, p[i].tt);
        avwt += p[i].wt;
        avtt += p[i].tt;
    }
    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------------\n\t");
    for (i = 0; i < num; i++) {
        printf("|");
        printf("%s\t", d[i].name);
    }
    printf(" |");
    printf("\n\t--------------------------------------------------------------------------\n\t");
    for (i = 0; i < num; i++) {
        printf("%d\t", d[i].st);
    }
    printf("%d\t", d[num - 1].ct);
    printf("\n\nAVERAGE WAITING TIME : %f", (avwt / n));
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (avtt / n));
}
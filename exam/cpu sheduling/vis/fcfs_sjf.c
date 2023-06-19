#include <stdio.h>
#include <stdlib.h>
struct processTerm
{
    char name[5];
    int arrival_time;
    int burst_time;
    int wait_time;
    int turnaround_time;
};
typedef struct processTerm pt;
void main()
{
    pt process[10];
    int n, i, j;
    printf("enter number of processes");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter process name: ");
        scanf("%s", process[i].name);
        printf("enter arrival time: ");
        scanf("%d", &process[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &process[i].burst_time);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (process[j].arrival_time > process[j + 1].arrival_time)
            {
                pt temp = process[j + 1];
                process[j + 1] = process[j];
                process[j] = temp;
            }
        }
    }

    printf("first come first serve scheduling: \n");
    process[0].wait_time = 0;
    process[0].turnaround_time = process[0].wait_time + process[0].burst_time;
    int sum1 = process[0].wait_time;
    int sum2 = process[0].turnaround_time;

    for (i = 0; i < n; i++)
    {
        process[i].wait_time = process[i - 1].wait_time + process[i - 1].burst_time;
        process[i].turnaround_time - process[i].wait_time + process[i].burst_time;
        sum1 = sum2 + process[i].wait_time;
        sum2 = sum2 + process[i].turnaround_time;
    }

    printf("Average waiting time is %f\n", sum1 / (float)n);
    printf("Average turnaround time is %f\n", sum2 / (float)n);

    for (i = 0; i < n; i++)
    {
        printf("process: %s Arrival time: %d Wait_time:%d\n Turnaround time: %d\n", process[i].name, process[i].arrival_time, process[i].wait_time, process[i].turnaround_time);
    }

    printf("shortest job first scheduling: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (process[j].burst_time > process[j + 1].arrival_time)
            {
                pt temp = process[j + 1];
                process[j + 1] = process[j];
                process[j] = temp;
            }
        }
    }

    process[0].wait_time = 0;
    process[0].turnaround_time = process[0].wait_time + process[0].burst_time;
    sum1 = process[0].wait_time;
    sum2 = process[0].turnaround_time;

    for (i = 0; i < n; i++)
    {
        process[i].wait_time = process[i - 1].wait_time + process[i - 1].burst_time;
        process[i].turnaround_time - process[i].wait_time + process[i].burst_time;
        sum1 = sum2 + process[i].wait_time;
        sum2 = sum2 + process[i].turnaround_time;
    }

    printf("Average waiting time is %f\n", sum1 / (float)n);
    printf("Average turnaround time is %f\n", sum2 / (float)n);

    for (i = 0; i < n; i++)
    {
        printf("process: %s Arrival time: %d Wait time:%d\n Turnaround time: %d\n", process[i].name, process[i].arrival_time, process[i].wait_time, process[i].turnaround_time);
    }
}

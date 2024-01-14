#include <stdio.h>

struct Process
{
    int processNumber;
    int arrivalTime;
    int burstTime;
};

int main()
{

    struct Process processes[10];

    for (int i = 0; i < 3; ++i)
    {
        printf("Enter details for Process %d:\n", i + 1);

        printf("Process Number: ");
        scanf("%d", &processes[i].processNumber);

        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);

        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);

        printf("\n");
    }
    for (int i = 0; i < 3; ++i)
    {
        printf("process: %d\n", processes[i].processNumber);
        printf("arrival time: %d\n", processes[i].arrivalTime);
        printf("burst time: %d\n\n", processes[i].burstTime);
    }
    int completionTime = 0;
    int turnAroundTime;
    int waitingTime;
    for (int i = 0; i < 3; ++i)
    {
        printf("process: %d\n", processes[i].processNumber);

        completionTime = processes[i].burstTime + completionTime;
        turnAroundTime = completionTime - processes[i].arrivalTime;
        waitingTime = turnAroundTime - processes[i].burstTime;
        printf("completion time: %d\n", completionTime);
        printf("turn around time: %d\n", turnAroundTime);
        printf("the waiting time is: %d\n", waitingTime);
    }

    return 0;
}

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

    for (int i = 0; i < 5; ++i)
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

    for (int i = 0; i < 5 - 1; ++i)
    {
        for (int j = 0; j < 5 - i - 1; ++j)
        {
            if (processes[j].burstTime > processes[j + 1].burstTime)
            {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("------------------------------------------------------------------------––\n");
    printf("| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("------------------------------------------------------------------------\n");

    int completionTime = 0;
    int turnAroundTime;
    int waitingTime;

    for (int i = 0; i < 5; ++i)
    {
        printf("| %-7d | %-13d | %-10d | %-16d | %-15d | ",
               processes[i].processNumber, processes[i].arrivalTime,
               processes[i].burstTime, completionTime,
               (completionTime - processes[i].arrivalTime));

        waitingTime = (completionTime - processes[i].arrivalTime - processes[i].burstTime) >= 0
                          ? (completionTime - processes[i].arrivalTime - processes[i].burstTime)
                          : 0;

        printf("%-12d |\n", waitingTime);

        completionTime = (completionTime < processes[i].arrivalTime) ? processes[i].arrivalTime : completionTime;
        completionTime += processes[i].burstTime;
    }

    printf("------------------------------------------------------------------------\n");

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct process
{
    int max[3];
    int allocated[3];
    int need[3];
    bool completed;
};

bool enoughresource(struct process p, int request[3], int available[3])
{
    for (int i = 0; i < 3; i++)
    {
        if (request[i] > p.need[i] || request[i] > available[i])
        {
            return false;
        }
    }
    return true;
}

void allocateResources(struct process *p, int request[3])
{
    for (int i = 0; i < 3; i++)
    {
        p->allocated[i] += request[i];
        p->need[i] -= request[i];
    }
}

bool bankeralgo(struct process *p, int count, int *res)
{
    int resavailable[3];

    for (int i = 0; i < 3; i++)
    {
        resavailable[i] = res[i];
    }

    int num_completed = 0;
    while (num_completed < count)
    {
        bool allocated = false;

        for (int i = 0; i < count; i++)
        {
            if (!p[i].completed && enoughresource(p[i], p[i].need, resavailable))
            {
                allocateResources(&p[i], p[i].need);
                for (int j = 0; j < 3; j++)
                {
                    resavailable[j] -= p[i].need[j];
                }
                p[i].completed = true;
                allocated = true;
                num_completed++;
            }
        }

        if (!allocated)
        {
            // If no processes can be allocated, break the loop to avoid an infinite loop
            break;
        }
    }

    // Check if all processes can finish
    return num_completed == count;
}

int main()
{
    int num_processes, num_resources;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    struct process *p = malloc(num_processes * sizeof(struct process));
    int *res = malloc(num_resources * sizeof(int));

    for (int i = 0; i < num_resources; i++)
    {
        printf("Enter the total resources available for resource %d: ", i + 1);
        scanf("%d", &res[i]);
    }

    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter the maximum resources for Process %d: ", i + 1);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &p[i].max[j]);
        }

        printf("Enter the allocated resources for Process %d: ", i + 1);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &p[i].allocated[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocated[j];
        }
    }

    if (bankeralgo(p, num_processes, res))
    {
        printf("The system is in a safe state.\n");
    }
    else
    {
        printf("The system is in an unsafe state.\n");
    }

    free(p);
    free(res);

    return 0;
}

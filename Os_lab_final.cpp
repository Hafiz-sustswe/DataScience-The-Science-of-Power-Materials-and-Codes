/**
C Program to Implement SJF Scheduling
*/

#include <stdio.h>
int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d", &n);
    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    // sorting of burst times
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;

                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    // finding the waiting time of all the processes
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            // individual WT by adding BT of all previous completed processes
            wt[i] += bt[j];
        // total waiting time
        total += wt[i];
    }
    // average waiting time
    avg_wt = (float)total / n;
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        // turnaround time of individual processes
        tat[i] = bt[i] + wt[i];
        // total turnaround time
        totalT += tat[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    // average turnaround time
    avg_tat = (float)totalT / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f", avg_tat);
}








//Priority(non - preemptive) :
/**
C program to implement priority scheduling
*/
#include <stdio.h>
                             // Function to swap two variables
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n,m;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    // b is array for burst time, p for priority and index for process id
    int b[n], p[n], index[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        int a = p[i], m = i;
        // Finding out highest priority element and placing it at its desired position
        for (int j = i; j < n; j++)
        {
            if (p[j] > a)
            {
                a = p[j];
                m = j;
            }
        }
        // Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i], &index[m]);
    }
    // T stores the starting time of process
    int t = 0;
    // Printing scheduled process
    printf("Order of process Execution is\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }
    printf("\n");
    printf("Process Id Burst Time Wait Time TurnAround Time\n");
    int wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d %d %d %d\n", index[i], b[i], wait_time, wait_time + b[i]);
        wait_time += b[i];
    }
    return 0;
}


//Round RObin

#include <stdio.h>
#include <conio.h>
void main()
{
    // initlialize the variable name
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf(" Total number of process in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of process to variable y
    // Use for loop to enter the details of the process like Arrival time and the Burst Time
    for (i = 0; i < NOP; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time is: \t"); // Accept arrival time
        scanf("%d", &at[i]);
        printf(" \nBurst time is: \t"); // Accept the Burst time
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // store the burst time in temp array
    }                    // Accept the Time qunat
    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);
    // Display the process No, burst time, Turn Around Time and the waiting time
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] >
                                    0) // define the conditions
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    // represents the average waiting time and Turn Around time
    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);
    getch();
}



// Banker's Algorithm
#include <stdio.h>
int main()
{
    // P0, P1, P2, P3, P4 are the Process names here
    int n, m, i, j, k;
    n = 5;                         // Number of processes
    m = 3;                         // Number of resources
    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4
    int max[5][3] = {{7, 5, 3},    // P0 // MAX Matrix
                     {3, 2, 2},    // P1
                     {9, 0, 2},    // P2
                     {2, 2, 2},    // P3
                     {4, 3, 3}};   // P4
    int avail[3] = {3, 3, 2};      // Available Resources
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y =
        0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }
    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }
    return (0);
    
}

// Resource allocation graph


//#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maxAllocation[MAX_PROCESSES][MAX_RESOURCES];
int currentAllocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finished[MAX_PROCESSES];

void initializeData(int numProcesses, int numResources) {
    int i, j;

    printf("Enter the available resources:\n");
    for (i = 0; i < numResources; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }

    printf("\nEnter the maximum allocation matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("For Process %d:\n", i);
        for (j = 0; j < numResources; j++) {
            printf("Resource %d: ", j);
            scanf("%d", &maxAllocation[i][j]);
        }
    }

    printf("\nEnter the current allocation matrix:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("For Process %d:\n", i);
        for (j = 0; j < numResources; j++) {
            printf("Resource %d: ", j);
            scanf("%d", &currentAllocation[i][j]);
            need[i][j] = maxAllocation[i][j] - currentAllocation[i][j];
        }
    }

    for (i = 0; i < numProcesses; i++) {
        finished[i] = false;
    }
}

bool isSafeState(int numProcesses, int numResources) {
    int work[MAX_RESOURCES];
    bool canFinish;
    int i, j, k;

    for (i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    for (i = 0; i < numProcesses; i++) {
        if (finished[i] == false) {
            canFinish = true;

            for (j = 0; j < numResources; j++) {
                if (need[i][j] > work[j]) {
                    canFinish = false;
                    break;
                }
            }

            if (canFinish) {
                finished[i] = true;

                for (k = 0; k < numResources; k++) {
                    work[k] += currentAllocation[i][k];
                }

                i = -1;  // Start over to recheck processes from the beginning
            }
        }
    }

    for (i = 0; i < numProcesses; i++) {
        if (finished[i] == false) {
            return false;
        }
    }

    return true;
}

int main() {
    int numProcesses, numResources;
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    initializeData(numProcesses, numResources);

    if (isSafeState(numProcesses, numResources)) {
        printf("\nThe system is in a safe state.\n");
    } else {
        printf("\nThe system is NOT in a safe state.\n");
    }

    return 0;
}

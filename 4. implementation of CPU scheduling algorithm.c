#include <stdio.h>

typedef struct {
    int id;
    int bt;
    int wt;
} Process;

void fcfs(Process p[], int n);

int main() {
    int i, n;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    Process p[n];

    printf("Enter burst time for each Process:\n");
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d:\n", p[i].id);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }

    fcfs(p, n);

    return 0;
}

void fcfs(Process p[], int n) {
    int i;
    float avg_wt = 0;

    printf("First Come First Serve (FCFS):\n");
    p[0].wt = 0;

    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        avg_wt = avg_wt + p[i].wt;
    }

    printf("Process\t Burst Time\t Waiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\n", p[i].id, p[i].bt, p[i].wt);
    }

    avg_wt = avg_wt / n;
    printf("Average Waiting Time: %f\n", avg_wt);
}

/* Output
student@BTECH-MACHINELEARNINGLAB:~/Documents/Windows$ gcc prac4.c
student@BTECH-MACHINELEARNINGLAB:~/Documents/Windows$ ./a.out
Enter the number of Processes: 3
Enter burst time for each Process:
Process 1:
Burst Time: 24
Process 2:
Burst Time: 3
Process 3:
Burst Time: 3
First Come First Serve (FCFS):
Process  Burst Time   Waiting Time
1        24           0
2        3            24
3        3            27
Average Waiting Time: 17.000000
*/

#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, pr;
    int rt, ct, tat, wt;
};

int main() {
    int n, time = 0, completed = 0, highest;
    struct process p[10];
    int is_completed[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].rt = p[i].bt;
    }

    while(completed < n) {
        highest = -1;
        int max_priority = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && is_completed[i] == 0) {
                if(p[i].pr > max_priority) {
                    max_priority = p[i].pr;
                    highest = i;
                }
            }
        }

        if(highest == -1) {
            time++;
        } 
        else {
            p[highest].rt--;
            time++;

            if(p[highest].rt == 0) {
                p[highest].ct = time;
                p[highest].tat = p[highest].ct - p[highest].at;
                p[highest].wt = p[highest].tat - p[highest].bt;
                is_completed[highest] = 1;
                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid, p[i].at, p[i].bt, p[i].pr,
        p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}

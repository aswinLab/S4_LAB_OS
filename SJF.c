#include <stdio.h>

struct process {
    int BT;
    int CT;
    int TAT;
    int WT;
}p[5];

int n = 5;
struct process temp[1];

void swap(int i, int j) {
    temp[1] = p[i];
    p[i] = p[j];
    p[j] = temp[1];
}

void Sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].BT > p[j + 1].BT)
                swap(j, j + 1);
        }
    }
}

int main() {
    
    
    p[0].BT = 45;
    p[1].BT = 43;
    p[2].BT = 21;
    p[3].BT = 78;
    p[4].BT = 30;
    //p[3].BT = 9;
    
    Sort();
        
    p[0].WT = 0;
    p[0].TAT = p[0].BT;
    p[0].CT = p[0].BT;
    
    for (int i = 1; i < n; i++) {
        p[i].WT = p[i - 1].WT + p[i - 1].BT;
        p[i].TAT = p[i].WT + p[i].BT;
        p[i].CT = p[i].TAT;
    }
    
    printf("+---------+----+----+-----+----+\n");
    printf("| Process | BT | WT | TAT | CT |\n" );
    printf("+---------+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| P%-7d | %-2d | %-2d | %-3d | %-2d |\n", i + 1, p[i].BT, p[i].WT, p[i].TAT, p[i].CT);
    }
    printf("+---------+----+----+-----+----+\n");
    
    float tot_WT = 0, tot_TAT = 0;
    for (int i = 0; i < n; i++) {
        tot_WT += p[i].WT;
        tot_TAT += p[i].TAT;
    }
    
    printf("\nAverage WT: %.2f\n", tot_WT / n);
    printf("Average TAT: %.2f\n", tot_TAT / n);
    
    return 0;
}

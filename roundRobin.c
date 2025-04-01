#include <stdio.h>

struct process {
    int BT;     
    int CT;     
    int TAT;    
    int WT;     
    int Left;
};

int main() {
    int TQ = 2; 
    int n = 3;   
    struct process p[n];
    
    p[0].BT = 5;
    p[1].BT = 8;
    p[2].BT = 12;

    int total_BT = 0;
    for (int i = 0; i < n; i++) {
        total_BT += p[i].BT;
        p[i].Left = p[i].BT;  
    }
    
    int currentTime = 0;  
    int completed = 0;    

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].Left > 0) {
                
                int timeToExecute = (p[i].Left < TQ) ? p[i].Left : TQ;
                p[i].Left -= timeToExecute;
                currentTime += timeToExecute;

                
                if (p[i].Left == 0) {
                    p[i].CT = currentTime;
                    p[i].TAT = p[i].CT;  
                    p[i].WT = p[i].TAT - p[i].BT;  
                    completed++;
                }
            }
        }
    }

    
    printf("+---------+----+----+-----+----+\n");
    printf("| Process | BT | WT | TAT | CT |\n");
    printf("+---------+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| P%-7d | %-2d | %-2d | %-3d | %-2d |\n", i + 1, p[i].BT, p[i].WT, p[i].TAT, p[i].CT);
    }
    printf("+---------+----+----+-----+----+\n");
    
    // Calculate average WT and TAT
    float tot_WT = 0, tot_TAT = 0;
    for (int i = 0; i < n; i++) {
        tot_WT += p[i].WT;
        tot_TAT += p[i].TAT;
    }

    printf("\nAverage WT: %.2f\n", tot_WT / n);
    printf("Average TAT: %.2f\n", tot_TAT / n);

    return 0;
}


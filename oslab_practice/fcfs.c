#include<stdio.h>
void findwaitingtime(int processes[],int n,int bt[],int wt[]){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
}
void findturnaround(int processes[],int n,int bt[],int tat[],int wt[]){
    for(int i=1;i<n;i++){
        tat[i]=wt[i]+bt[i];
    }
}




void findavgtime(int processes[],int n,int bt[]){
    float total_wt = 0;
    float total_tat = 0;
    int tat[n];
    int wt[n];
    findwaitingtime(processes,n,bt,wt);
    findturnaround(processes,n,bt,tat,wt);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("/n average waiting time is %.2f ",total_wt/n);
    printf("/n average turnaround time is %.2f ",total_tat/n);
}
int main(){
    int processes[] = {1,2,3,4};
    int n = sizeof processes/sizeof processes[0];
    int burst_time[] = {6,4,8,3};
    findavgtime(processes,n,burst_time);
}
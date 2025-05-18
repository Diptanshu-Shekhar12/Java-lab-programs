#include<stdio.h>
int main(){
int n;
printf("enter number of processes");
scanf("%d",&n);
float total_wt = 0;
float total_tat = 0;
int bt[n],wt[n],tat[n],queue[n];
for(int i=0;i<n;i++){
    printf("enter burst time and qeueu type(1=system and 2=user) for process %d",i+1);
    scanf("%d %d",&bt[i],&queue[i]);
}
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
        if(queue[j]>queue[j+1]){
            int temp = bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
            temp = queue[j];
            queue[j]=queue[j+1];
            queue[j+1]=temp;
        }
    }

}
wt[0]=0;
tat[0]=bt[0];
for(int i=1;i<n;i++){
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=wt[i]+bt[i];
    total_tat += tat[i];
    total_wt +=wt[i];
}
 printf("\nProcess\tQueue Type\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, queue[i], bt[i], wt[i], tat[i]);
    }
    printf("average waiting time is %.2f ",total_wt/n);
    printf("\n");
    printf("average turnaround time is %.2f ",total_tat+tat[0]/n);


}

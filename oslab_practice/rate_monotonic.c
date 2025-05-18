#include<stdio.h>
#define MAX_TASKS 5
typedef struct{
int id;
int exe_time;
int rem_time;
int period;
}Task;
void sort_task_by_period(Task tasks[],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
        if(tasks[j].period>tasks[j+1].period){
            Task temp = tasks[j];
            tasks[j]=tasks[j+1];
            tasks[j+1]=temp;
        }
    }
}}
void rate_monotonic(Task tasks[],int n,int hyperperiod){
printf("\n rate montononic scheduling\n");
for(int t=0;t<hyperperiod;t++){
    int runningtask = -1;
    for(int i=0;i<n;i++){
        if(tasks[i].rem_time>0){
            runningtask = i;
            break;
        }
    }
    if(runningtask!=-1){
        printf("\ntime %d: Task %d is running\n",t,tasks[runningtask].id);
        tasks[runningtask].rem_time--;
    }else{
    printf("\ntime %d : idle\n",t);

    }
    for(int i=0;i<n;i++){
        if((t+1)%tasks[i].period==0){
            tasks[i].rem_time=tasks[i].exe_time;
        }
    }
}
}

int main(){
int n;
printf("enter number of tasks : ");
scanf("%d",&n);
int hyperperiod = 1;
Task tasks[MAX_TASKS];
for(int i=0;i<n;i++){
    printf("enter execution time and period for task %d",i+1);
    scanf("%d %d",&tasks[i].exe_time,&tasks[i].period);
    tasks[i].rem_time = tasks[i].exe_time;
    hyperperiod*=tasks[i].period;
    tasks[i].id = i+1;
}
sort_task_by_period(tasks,n);
rate_monotonic(tasks,n,hyperperiod);
}

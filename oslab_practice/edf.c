
#include<stdio.h>
#define MAX_TASKS 5
typedef struct{
int id;
int exe_time;
int rem_time;
int period;
int next_deadline;
}Task;
int gcd(int a,int b){
if(b==0)return a;
else{
    return gcd(b,a%b);
}}
int lcm(int a,int b){
return (a*b)/gcd(a,b);}

void edf(Task tasks[],int n,int hyperperiod){
printf("\n edf scheduling\n");
for(int t=0;t<hyperperiod;t++){

    for(int i=0;i<n;i++){
        if(t%tasks[i].period==0){
            tasks[i].rem_time = tasks[i].exe_time;
            tasks[i].next_deadline = t+tasks[i].period;
        }
    }
     int runningtask = -1;
     int min_deadline = 99999;
     for(int i=0;i<n;i++){
        if(tasks[i].rem_time>0 && tasks[i].next_deadline<min_deadline){
                min_deadline = tasks[i].next_deadline;
            runningtask = i;
        }
     }
    if(runningtask!=-1){
        printf("\ntime %d: Task %d is running\n",t,tasks[runningtask].id);
        tasks[runningtask].rem_time--;
    }else{
    printf("\ntime %d : idle\n",t);

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
    tasks[i].rem_time = 0;
    tasks[i].next_deadline = tasks[i].period;
    hyperperiod = lcm(hyperperiod,tasks[i].period);

    tasks[i].id = i+1;
}

edf(tasks,n,hyperperiod);
}

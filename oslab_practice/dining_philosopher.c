#include<stdio.h>
#include<semaphore.h>
 #define N 5
 sem_t forks[N];
 int state[N];
 //0=think 1= hungry 2=eat

 void pickup_forks(int i){
 if(state[i]==1 && state[(i+N-1)%N]!=2 && state[(i+1)%N]!=2 ){
    state[i]=2;
    sem_wait(&forks[i]);
    sem_wait(&forks[(i+1)%N]);
    printf("philosopher %d is eating ",i);

 }else{
 printf("philosopher %d cant eat now",i);
 }}

 void putdown_forks(int i){
 state[i]=0;
 sem_post(&forks[i]);
    sem_post(&forks[(i+1)%N]);
    printf("philosopher %d has done eating",i);

 }
 int main(){
 for(int i=0;i<N;i++){
    state[i] = 0;
    sem_init(&forks[i],0,1);

 }
 int choice;
 int philosopher;
 while(1){
    printf("\n1.philosopher is hungry\n 2. Philosopher puts down fork\n 3.exit\n");
    printf("enter choice: ");
    scanf("%d",&choice);
     if(choice==1){
         printf("Enter philosopher number (0 to 4): ");
         scanf("%d", &philosopher);
         state[philosopher]=1;
         pickup_forks(philosopher);
     }else if(choice==2){
        printf("Enter philosopher number (0 to 4): ");
        scanf("%d", &philosopher);
        putdown_forks(philosopher);

     }else if(choice==3){
     break;}
     else{
        printf("invalid choice");
     }

 }
 }

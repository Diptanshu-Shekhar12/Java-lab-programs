#include <stdio.h>
#include <semaphore.h>
#define SIZE 5
sem_t full,empty,mutex;
int buffer[SIZE];
int in=0;
int out = 0;
void producer(){
sem_wait(&empty);
sem_wait(&mutex);
buffer[in] = in+1;
printf(" produced %d at position %d",buffer[in],in);
in = (in+1)%SIZE;
sem_post(&mutex);
sem_post(&full);

}
void consumer(){
sem_wait(&full);
sem_wait(&mutex);
int temp = buffer[out];
printf("consumed %d at position %d",temp,out);
out = (out+1)%SIZE;
sem_post(&mutex);
sem_post(&empty);
}
int main(){
int choice;
sem_init(&mutex,0,1);
sem_init(&empty,0,SIZE);
sem_init(&full,0,0);
while(1){
     printf("\n1. Produce\n2. Consume\n3. Exit\nChoice: ");
     scanf("%d",&choice);
     switch(choice){
     case 1:{
     int value;
     sem_getvalue(&empty,&value);
     if(value==0){
        printf("buffer full ,cannot produce\n");

     }
     else{
        producer();
     }
     break;
     }
     case 2 :{
     int value;
     sem_getvalue(&full,&value);
     if(value==0){
        printf("buffer full ,cannot consume\n");

     }
     else{
        consumer();
     }
     break;
     }
     case 3:
     sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                return 0;

     default: printf("invalid input \n");
     }

}
}

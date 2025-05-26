#include<stdio.h>

void sortitems(int profit[],int weight[],int index[],int n){
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){
            float r1 = (float)profit[j]/weight[j];
            float r2 = (float)profit[j+1]/weight[j+1];
    if(r1<r2){
        int temp = profit[j];
        profit[j]=profit[j+1];
        profit[j+1]=temp;

        int temp = weight[j];
        weight[j]=weight[j+1];
        weight[j+1]=temp;

        int temp = index[j];
        index[j]=index[j+1];
        index[j+1]=temp;

    }

    }
}
}
void knapsack(int profit[],int weight[],int index[],int n,int c){
float total_p = 0.0;
float fraction[n];
for(int i=0;i<n;i++){
    fraction[i]=0.0;
}
for(int i=0;i<n;i++){
    if(c==0)break;
    if(weight[i]<=c){
        total_p+=profit[i];
        c-=weight[i];
        fraction[i]=1.0;
    }else{
    float frac = (float)c/weight[i];
    total_p+=frac*profit[i];
    fraction[i]=frac;
    c = 0;
    }
}
printf("\nmax profit is %d\n",total_p);
printf("item wise selection\n");
printf("item\tprofit\tweight\tfraction taken");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d",index[i],profit[i],weight[i],fraction[i]);
}

}

int main(){
int n;
printf("enter number of objects");
scanf("%d",&n);
int c;
printf("enter capcacity of knapsack");
scanf("%d",&c);
int profit[n],weight[n],index[n];
for(int i=0;i<n;i++){
    printf("enter profit and weight of item %d",i+1);
    scanf("%d %d",&profit[i],&weight[i]);
    index[i]=i+1;
}
sortitems(profit,weight,index,n);
knapsack(profit,weight,index,n,c);
}

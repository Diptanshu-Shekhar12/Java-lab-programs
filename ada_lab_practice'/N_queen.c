#include<stdio.h>
#include<math.h>
int x[20];
int count =1;
int place(int k,int j){
for(int i=1;i<k;i++){
    if(x[i]==j || abs(x[i]-j)==abs(i-k))return 0;
}
return 1;
}

void queen(int n,int k){
for(int j=1;j<=n;j++){
    if(place(k,j)){
        x[k]=j;
        if(k==n){
            printf("solution %d\n",count);
            count++;
            for(int i=1;i<=n;i++){
            printf("\n\t%d row---%d column",i,x[i]);
        }}else{
        queen(n,k+1);
        }


}
}}

int main(){
int n;
int k=1;
printf("enter number of queens");
scanf("%d",&n);
queen(n,k);
}

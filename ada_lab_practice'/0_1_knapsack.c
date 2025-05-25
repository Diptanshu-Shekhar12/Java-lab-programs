#include<stdio.h>
int i,j,c,n;
int w[10],p[10];
int v[10][10];
int max(int a, int b){
    if(a>b)return a;
    else return b;
}
void knapsack(int n,int c,int w[10],int p[10]){
for( i=0;i<=n;i++){
    for( j=0;j<=c;j++){
        if(i==0 || j==0){
            v[i][j]=0;
        }else if(w[i]>j){
        v[i][j]=v[i-1][j];
        }else{
        v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
    }
}
printf("\nmax profit is %d: ",v[n][c]);
printf("\ntable\n");
for(i=0;i<=n;i++){
    for(j=0;j<=c;j++){
        printf("\t%d",v[i][j]);
    }
    printf("\n");
}
}
int main(){
printf("enter number of objects: ");
scanf("%d",&n);
printf("\nenter weights of the objects: ");
for( i=1;i<=n;i++){
    scanf("%d",&w[i]);
}
printf("\nenter profits of the objects: ");
for( i=1;i<=n;i++){
    scanf("%d",&p[i]);
}
printf("enter capacity of the bag:");
scanf("%d",&c);
knapsack(n,c,w,p);
}

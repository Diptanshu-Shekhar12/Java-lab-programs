#include<stdio.h>
int main(){
int v,n,u,min;
int c[20][20];
int s[20];
int d[20];
printf("enter number of vertices");
scanf("%d",&n);
printf("enter source vertex");
scanf("%d",&v);
printf("enter cost matrix");
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        scanf("%d",&c[i][j]);
    }
}
for(int i=1;i<=n;i++){
    s[i]=0;
    d[i]=c[v][i];
}
d[v]=0;
s[v]=1;
for(int k=2;k<=n;k++){
    min = 999;
    for(int i=1;i<=n;i++){
        if(s[i]==0 && d[i]<min){
            min = d[i];
            u = i;
        }
    }
    s[u]=1;
    for(int i=1;i<=n;i++){
        if(s[i]==0 && d[i]>d[u]+c[u][i]){
            d[i]=d[u]+c[u][i];
        }
    }
}
printf("\nshortest distance from vertex %d are\n",v);
for(int i=1;i<=n;i++){
    printf("%d-->%d = %d\n",v,i,d[i]);
}


}

#include<stdio.h>
int a[10][10],res[10],v[10];
int n;
int top = 0;
void dfs(int j,int a[10][10],int n){
v[j]=1;
for(int i=0;i<n;i++){
    if(v[i]==0 && a[j][i]==1){
        dfs(i,a,n);
    }
}
res[top++]=j;

}


void dfs_top(int n,int a[10][10]){
for(int i=0;i<n;i++){
    v[i]=0;
}
for(int i=0;i<n;i++){
    if(v[i]==0){
        dfs(i,a,n);
    }
}

}

int main(){
printf("enter number of nodes: ");
scanf("%d",&n);
printf("enter input matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
dfs_top(n,a);
printf("\nsolution\n");
for(int i=n-1;i>=0;i--){
    printf("%d ",res[i]);
}
return 0;
}

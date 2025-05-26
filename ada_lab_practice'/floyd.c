#include<stdio.h>
int a[10][10];
int d[10][10];
int n;
int min(int a,int b){
if(a<b)return a;
else return b;
}
void floyd(int a[10][10],int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        d[i][j]=a[i][j];
    }
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j] = min(d[i][j],(d[i][k]+d[k][j]));
        }
    }
}
}
int main(){
printf("enmter number of vertices: ");
scanf("%d",&n);
printf("\n enter input matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
floyd(a,n);
printf("distance matrix is\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",d[i][j]);
    }
    printf("\n");
}

}

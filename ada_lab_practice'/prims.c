#include<stdio.h>
#define MAX 100
#define INF 999
int main(){
int cost[MAX][MAX];
int visited[MAX] = {0};
int u,v,n;
int edges = 0;
int min_cost = 0;
int min;
printf("enter number of vertices\n");
scanf("%d",&n);
printf("\nenter cost adjacency matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&cost[i][j]);
    }
}
 visited[0]=1;
while(edges<n-1){
    min = INF;
    u=v=0;
    for(int i=0;i<n;i++){
        if(visited[i]){
            for(int j=0;j<n;j++){
                if(!visited[j] && cost[i][j]<min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
    }
    visited[v]=1;
    printf("(%d %d) cost = %d \n",u,v,min);
    min_cost+=min;
    edges++;


}
printf("cost of mst is %d",min_cost);
}

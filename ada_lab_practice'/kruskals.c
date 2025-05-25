#include<stdio.h>
#define MAX 100
#define INF 999
int parent[MAX];
int find(int i){
while(parent[i])
    i = parent[i];
return i;
}
int uni(int i,int j){
if(i!=j){
    parent[j]=i;
    return 1;
}
return 0;
}
int main(){
int cost[MAX][MAX],a,b,u,v,n;
int min;
int min_cost = 0;
int edge = 1;
printf("enter number of vertices : ");
scanf("%d",&n);
printf("\n enter cost adjacency matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&cost[i][j]);
    }
}
printf("\ nedges of minimal spannning tree \n");
while(edge<n){
        min = INF;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(cost[i][j]<min){
            min = cost[i][j];
            a = u = i;
            b = v = j;
        }
    }
}
u = find(u);
v = find(v);
if(uni(u,v)){
    printf("(%d %d)\n",a,b);
    min_cost+=min;
    edge++;
}
cost[a][b]=cost[b][a]=INF;

}
printf("\n sum of minimal spanning tree is %d\n",min_cost);
}

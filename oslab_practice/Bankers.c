#include<stdio.h>
#define MAX 10
int main(){
int n,m;
int alloc[MAX][MAX],max[MAX][MAX],need[MAX][MAX];
int avail[MAX],work[MAX],finish[MAX];
int safeseq[MAX];
int count = 0;
printf("enter number of process: ");
scanf("%d",&n);
printf("enter number of resources :");
scanf("%d",&m);
    printf("enter allocation matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);

        }
    }
    printf("enter max matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);

        }
    }
    printf("enter avaiable resources\n");
    for(int j=0;j<m;j++){
        scanf("%d",&avail[j]);
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];

        }
    }
    for(int j=0;j<m;j++){
        work[j]=avail[j];
    }
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    while(count<n){
        int found =0;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                    int j;
                for( j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        break;
                    }
                }
                if(j==m){
                        for(int k=0;k<m;k++){
                            work[k]+=alloc[i][k];
                        }
                    safeseq[count++] = i;
                    found =1;
                    finish[i]=1;

                }
            }
        }
        if(found==0){
            printf("systenm is not in safe state");
            return 0;
        }
    }
    printf("safe seq is \n");
    for(int i=0;i<n;i++){
        printf("P%d",safeseq[i]);
        printf("\n");
    }
    return 0;
}

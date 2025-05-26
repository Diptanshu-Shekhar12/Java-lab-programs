#include<stdio.h>


int partition(int a[10],int lb,int ub){
int pivot = a[lb];
int start = lb;
int end = ub;
while(start<end){
    while(a[start]<=pivot)start++;
    while(a[end]>pivot)end--;
    int temp = a[start];
    if(start<end){
    a[start]=a[end];
    a[end]=temp;}
}
int temp = a[lb];
a[lb]=a[end];
a[end]=temp;
return end;
}

void quick_sort(int a[10],int lb,int ub){
int loc;
if(lb<ub){
    loc = partition(a,lb,ub);
    quick_sort(a,lb,loc-1);
    quick_sort(a,loc+1,ub);
}
}

int main(){
int n;
printf("enter number of elements");
scanf("%d",&n);
int a[n];
printf("\nenter elements\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
quick_sort(a,0,n-1);
printf("\nafter sorting\n");
for(int i=0;i<n;i++){
    printf("%d",a[i]);
}
}

#include<stdio.h>



void merge(int a[10],int low,int mid,int high){
int i = low;
int j = mid+1;
int k = 0;
int temp[high-low+1];
while(i<=mid && j<=high){
    if(a[i]<=a[j]){
        temp[k++]=a[i++];
    }else{
    temp[k++] = a[j++];
    }
}
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=high){
        temp[k++]=a[j++];
    }
    for(int i=0;i<k;i++){
        a[low+i]=temp[i];
    }
}

void merge_sort(int a[10],int low,int high){
if(low>=high)return;
int mid = (low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
merge(a,low,mid,high);
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
merge_sort(a,0,n-1);
printf("\nafter sorting\n");
for(int i=0;i<n;i++){
    printf("%d",a[i]);
}
}

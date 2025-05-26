#include<stdio.h>
#include<stdlib.h>
void swap(int*a,int*b){
int temp = *a;
*a= *b;
*b = temp;
}
void generate_permutation(int arr[],int start,int end){
if(start==end){
    for(int i=0;i<=end;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}else{
for(int i=start;i<=end;i++){
    swap(&arr[i],&arr[start]);
    generate_permutation(arr,start+1,end);
     swap(&arr[i],&arr[start]);

}
}
}
int main(){
int n;
int* arr = (int*)malloc(n*sizeof(int));
printf("enter number of elements:");
scanf("%d",&n);
printf("enter the elements\n");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

}
generate_permutation(arr,0,n-1);
}

#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int left,int right,int mid){
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    int *leftArr = (int*)malloc(sizeof(int)*n1);
    int *rightArr = (int*)malloc(sizeof(int)*n2);
    for(i=0;i<n1;i++){
        leftArr[i] = arr[left+i];
    }
    for(j=0;j<n2;j++){
        rightArr[j] = arr[mid+1+j];
    }
    i=0;
    j=0;
    k = left;
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}
int main(){
    int arr[5];
    int i,j,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    printf("Enter the array data = \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray before sorting = \n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("\nArray after sorting = \n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}

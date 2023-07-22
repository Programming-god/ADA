#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int arr[],int low,int high){
    int pivot=arr[high],i=low-1,temp;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main(){
     struct timespec start, end;
    int n,arr[20];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    quicksort(arr,0,n-1);
     clock_gettime(CLOCK_MONOTONIC, &end);
     long long time_taken = (end.tv_sec - start.tv_sec) * 1000000000LL + end.tv_nsec - start.tv_nsec;

    // Convert to milliseconds for display
    double time_taken_ms = (double)time_taken / 1e6;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
  printf("\nTime taken: %lf milliseconds\n", time_taken_ms);
    printf("Time taken: %lld nanoseconds\n", time_taken);
    return 0;
}

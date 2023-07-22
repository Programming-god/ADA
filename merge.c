#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <string.h>

void merge(int arr[],int l,int m,int h){
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;
    int temp1[n1];
    int temp2[n2];
    for(int i=0;i<n1;i++){
        temp1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        temp2[i]=arr[m+i+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
        if(temp1[i]<temp2[j]){
            arr[k]=temp1[i];
            i++;
        }
        else{
            arr[k]=temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=temp1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=temp2[j];
        j++;
        k++;
    }

}

void mergesort(int arr[],int l, int h){
    if(l<h){
        int m=(l+h-1)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}


int main() {
    struct timespec start, end;
    int arr[100000], n, low, high;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    low = 0;
    high = n - 1;

    // Get the start time using CLOCK_MONOTONIC
    clock_gettime(CLOCK_MONOTONIC, &start);

    mergesort(arr, low, high);

    // Get the end time using CLOCK_MONOTONIC
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time taken in nanoseconds
    long long time_taken = (end.tv_sec - start.tv_sec) * 1000000000LL + end.tv_nsec - start.tv_nsec;

    // Convert to milliseconds for display
    double time_taken_ms = (double)time_taken / 1e6;

    // Print the sorted array and the time taken in milliseconds and nanoseconds
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %lf milliseconds\n", time_taken_ms);
    printf("Time taken: %lld nanoseconds\n", time_taken);

    return 0;
}

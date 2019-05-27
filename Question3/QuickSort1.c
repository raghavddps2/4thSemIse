/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Quick Sort

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
        *a = *b;
        *b = temp;
}

int partition(int *Array,int start,int end){

    //We consider last element as the pivot.
    int pivot = Array[end];
    int partitionIndex = start;
    for(int i=start;i<=end-1;i++){
        //If less than pivot, wap the partition index value and the current arrray value.
        if(Array[i]<=pivot){
            swap(&Array[i],&Array[partitionIndex]);
            partitionIndex++; //inc the partition index.
        }
    }
    //Swap the array with partition index and the end value, the pivot basicallly.
    swap(&Array[partitionIndex],&Array[end]);
    return partitionIndex;
}

void QuickSort(int *Array, int start, int end){

    //Only if start<end satisfies.
    if(start<end){
        int partitionIndex = partition(Array,start,end);  
            QuickSort(Array,start,partitionIndex-1);
            QuickSort(Array,partitionIndex+1,end);
    }
    else{
        return;
    }
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    //Filling the values in the array.
    for(int i=0;i<n;i++){
        Array[i] = rand()%1000;
    }

    int start = 0;
    int end = n-1;

    clock_t Tstart = clock();
    QuickSort(Array,start,end);
    clock_t Tend = clock();
 
    double time = ((double)(Tend-Tstart))/CLOCKS_PER_SEC;
    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\nThe time taken is %lf",time);
}
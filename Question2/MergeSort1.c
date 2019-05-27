/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: erge Sort

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Merge(int *Left, int *Right, int *Array, int nL,int nR, int n){

    int i=0; //for the left array
    int j=0; //for the right array
    int k=0; //for the original array

    //Compare between right and left subarrrays and then insert.
    while(i<nL && j<nR){
        if(Left[i]<=Right[j]){
            Array[k] = Left[i];
            i++;
        }
        else{
            Array[k] = Right[j];
            j++;
        }
        k++;
    }
    //Put all the remaining elements in left sub array
    while(i<nL){
        Array[k] = Left[i];
        k++;
        i++;
    }
    //Putting all the remaining elements in right sub array.
    while(j<nR){
        Array[k] = Right[j];
        j++;
        k++;
    }
}

void MergeSort(int *Array, int n){

    //If only one element then return.
    if(n<2){
        return;
    }

    int mid = n/2;
    int nL = mid;
    int nR = n-mid;
    int Left[nL];
    int Right[nR];

    //Putting values in the left half.
    for(int i=0;i<mid;i++){
        Left[i] = Array[i];
    }
    //Putting values in the right half.
    for(int j=mid;j<n;j++){
        Right[j-mid] = Array[j];
    }

    //Calling this function on left and right subarrays.
    MergeSort(Left,nL);
    MergeSort(Right,nR);
    //Calling the Merge function to merge the values obtained in order.
    Merge(Left,Right,Array,nL,nR,n);
}


void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    for(int i=0;i<n;i++){
        Array[i] = rand()%1000;
    }

    clock_t start = clock();
    MergeSort(Array,n);
    clock_t end = clock();

    double time = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nThe sorted array is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\nThe time taken to sort the array is %lf",time);
}
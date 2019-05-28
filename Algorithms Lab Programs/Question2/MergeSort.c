/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Merge Sort

*/
#include<stdio.h>

//Function to merge the values.
void Merge(int *Left, int *Right, int nL, int nR, int n,int *Array){

    int i=0,j=0,k=0;
    while(i<nL && j<nR){
        if(Left[i]<=Right[j]){
            Array[k] = Left[i];
            i++;
        }
        else{
            Array[k] = Right[j];
            j++;
        }
        k++; //Incrementing the main arrray pointer here.
    }
    //After this, we check if we have any element left in Left and write and we include them.

    while(i<nL){
        Array[k] = Left[i];
        k++;
        i++;
    }
    while(j<nR){
        Array[k] = Right[j];
        k++;
        j++;
    }
    //This way we merge the values in ascending order.
}

void MergeSort(int *Array, int n){

    //If only one element just retrun back,as no more sorting is required.
    if(n<2){
        return;
    }

    //Now we divide the array into two parts and then divide them furthur using the same function.
    int mid = n/2;
    int nL = mid; //Size of the left array
    int nR = n-mid; //Size of the right array.
    int Left[nL]; //We declare the Left array
    int Right[nR]; //We declare the right array.

    //Now we will put values in the array's.
    for(int i=0;i<mid;i++){
        Left[i] = Array[i];
    }
    for(int j=mid;j<n;j++){
        Right[j-mid] = Array[j];
    }
    MergeSort(Left,nL);
    MergeSort(Right,nR);

    Merge(Left,Right,nL,nR,n,Array);
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);
    int Array[n];
    printf("\nEnter the elements of teh array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }

    MergeSort(Array,n);

    printf("The sorted arrray is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
}
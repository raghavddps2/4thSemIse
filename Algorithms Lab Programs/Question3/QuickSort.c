/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Quick Sort

*/
#include<stdio.h>

void swap(int *val1, int *val2){
    int temp = *val1;
        *val1 = *val2;
        *val2 = temp;
}
int partition(int *Array,int start,int end){
    int pivot = Array[end];
    //Now, we will run a loop and if the element is lesser than the pivot, we swap the partitionIndex
    //value and the Current value of array while in loop. Later when we obtain the partition index,We swap
    //that element with the end.
    int partitionIndex = start;
        for(int i=start;i<=end-1;i++){
            if(Array[i]<=pivot){
                swap(&Array[i],&Array[partitionIndex]);
                partitionIndex++;
            }
        }
        //After this is done, we swap the partition index value and the end.
        swap(&Array[partitionIndex],&Array[end]);
        return partitionIndex;

}
void QuickSort(int *Array, int start, int end){

    //Partition index is basically something before which all elements are lesser than that and after 
    //which all elements are greater than that.
    if(start<end){
        int partitionIndex = partition(Array,start,end); 
        QuickSort(Array,start,partitionIndex-1); //Sort all the left elements.
        QuickSort(Array,partitionIndex+1,end);  //Sort all the right elements.
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
    printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }

    QuickSort(Array,0,n-1); 
    //We write as n-1, becuase our format for the function is QuickSort(Array,start,end),
    //here the end index is n-1 and not n!!!

    printf("\nThe sorted arrray is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
}
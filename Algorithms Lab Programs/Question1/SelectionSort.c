/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Selection Sort

*/
#include<stdio.h>

void main(){

    int n;
    printf("\nEnter the number of elements");
    scanf("%d",&n);
    int Array[n];
    printf("\nENter the elements of the array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }

    printf("\nSelection Sorting Begins....");
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(Array[j]<Array[min_index]){
                min_index = j;
            }
        }
        int temp = Array[min_index];
            Array[min_index] = Array[i];
            Array[i] = temp;
    }
    printf("\nSelection sorting ends...");

    printf("\nThe sorted arrray is:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
}
/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Bubble Sort

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//This is a sorting function.
void BubbleSort(int *Array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(Array[j]>Array[j+1]){
                int temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            }
        }
    }
}

void main(){
    int n; 
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    // printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        Array[i] = rand()%1000;
    }
    clock_t start = clock();
    BubbleSort(Array,n);
    clock_t end = clock();

    double time = ((double)(end-start))/CLOCKS_PER_SEC;
    

    printf("\n-----------------------------------------------\n");
    // printf("\nThe sorted elements are:\t");
    // for(int i=0;i<n;i++){
    //     printf("%d ",Array[i]);
    // }
    printf("\nThe time taken to sort the elements is: %lf\n",time);
    printf("\n-----------------------------------------------\n");
    



}
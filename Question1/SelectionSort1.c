/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Selection Sort

*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void SelectionSort(int *Array,int n){
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(Array[j]<Array[min_index]){
                min_index = j;
            }
        }
        int temp = Array[i];
            Array[i] = Array[min_index];
            Array[min_index] = temp;
    }
}

void main(){
    int n;
    printf("\nEnter the number of elements:\t");
    scanf("%d",&n);
    int Array[n];
    //Generating random numbers.
    for(int i=0;i<n;i++){
        Array[i] = rand()%1000;
    }

    clock_t start = clock();
    SelectionSort(Array,n);
    clock_t end = clock();
    double time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nThe elements are\n");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\nThe time taken to sort the elements is:\t%lf\n",time);
}
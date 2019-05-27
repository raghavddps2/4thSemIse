/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Heap Sort

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void heapify(int *Array,int n,int i){

    int largest = i;
    int leftChild = 2*i;
    int rightChild = (2*i) + 1;

    if(leftChild<n && Array[leftChild]>Array[largest]){
        largest = leftChild;
    }
    if(rightChild<n && Array[rightChild]>Array[largest]){
        largest = rightChild;
    }
    if(largest != i){
        int temp = Array[largest];
            Array[largest] = Array[i];
            Array[i] = temp;
        heapify(Array,n,largest);
    }
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    for(int i=1;i<=n;i++){
        Array[i] = rand()%1000;
    }
    clock_t start = clock();
    for(int i=n/2;i>=1;i--){
        heapify(Array,n,i);
    }

    for(int i=n;i>=1;i--){
        int temp = Array[1];
            Array[1] = Array[i];
            Array[i] = temp;
        heapify(Array,i,1);
    }
    clock_t end = clock();
    double time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\nThe sorted array is:\t");
    for(int i=1;i<=n;i++){
        printf("%d ",Array[i]);
    }
    printf("\nThe time taken is %lf\n",time);


}
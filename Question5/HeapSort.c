/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Heap Sort

*/
#include<stdio.h>

void heapify(int *Array,int n, int i){

    int largest = i;
    int leftChild = 2*i;
    int rightCHild = (2*i)+1;

    //if leftchild is less than n, and the value is larger than Array[largest], we put leftCHild in largest.
    if(leftChild<n && Array[leftChild]>Array[largest]){
        largest = leftChild;
    }
    //if rightchild is less than n and the value if larger than tha Array[largest], we again put that into it.
    if(rightCHild<n && Array[rightCHild]>Array[largest]){
        largest = rightCHild;
    }
    //Once we get that, we have to swap it, if largest is not w=equal to i (Same as before.)
    if(largest != i){
        int temp = Array[largest];
        Array[largest] = Array[i];
        Array[i] = temp;
    //After you are done with swapping, we have toagain call the heapify function.
        heapify(Array,n,largest);
    }
    
}

void main(){
    int n;
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    printf("\nEnter the elements of the array:\t");
    for(int i=1;i<=n;i++){
        scanf("%d",&Array[i]);
    }

    //Now, as we take the array, we consider it as a heap, now we will convert it to a max heap.
    //We will only consider from n/2 till 1, as we wont include the leaf nodes.
    for(int i=n/2;i>=1;i--){
        heapify(Array,n,i);
    }

    //Now, once the elements are heapified, we start with the last value and swap with tthe fist one
    //and then delete it,and it is then at the end of thearray, that will be the greatest.
    for(int i=n;i>=1;i--){

        int temp = Array[i];
            Array[i] = Array[1];
            Array[1] = temp;
        //We again call the heapify function to convert back to a max heap.
        heapify(Array,i,1); //here, we have to start from 1.
    }

    //For printing.
    printf("\nThe elements of the array are:\t");
    for(int i=1;i<=n;i++){
        printf("%d ",Array[i]);
    }
}
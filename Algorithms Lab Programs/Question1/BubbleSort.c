/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Bubble Sort

*/
#include<stdio.h>

void main(){
    int n;
    //Takes input for the number of elements.
    printf("\nEnter the number of elements in the array:\t");
    scanf("%d",&n);

    int Array[n];
    //Takes the number of elements.
    printf("\nEnter the elements of the array:\t");
    for(int i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }
    //The below is the actual bubble sorting code.
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(Array[j]>Array[j+1]){
                int temp = Array[j];
                    Array[j] = Array[j+1];
                    Array[j+1] = temp;
            }
        }
    }
    //The sorting code ends here.

    //This prints the array in sorted order.
    printf("\n-------------------------------------------------\n");
    printf("\nThe elements in the sorted order are:\t");
    for(int i=0;i<n;i++){
        printf("%d ",Array[i]);
    }
    printf("\n-------------------------------------------------\n");
    printf("\n");
}


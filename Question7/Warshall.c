/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Warshalls ALgorithm

    Please note that the warshalls algorithm is used to find the transitive closure of a graph, 
    we consider a directed graph for the same.
*/

#include<stdio.h>
//This aptly represents how we pass a 2D array to a function using pointers.
void warshall(int n,int(*Array)[n]){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                *(*(Array + i)+j) = *(*(Array+i)+j) || ( (*(*(Array+i)+k)) && (*(*(Array+k)+j)) );
            }
        }
    }
}

void main(){
    int n;
    printf("\n Enter the number of vertices:\t");
    scanf("%d",&n);

    int Array[n][n];
    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Array[i][j]);
        }
    }

    warshall(n,Array);

    printf("\nThe transitive closure is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",Array[i][j]);
        }
        printf("\n");
    }
}
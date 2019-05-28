/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Floyds Algorithm

    This algorithm is basically used to calculate the shortest distance between all pairs of vertices.
    Hence this is called as the All Pairs shortest path problem.
*/
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

void Floyds(int n,int (*Array)[n]){

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                *(*(Array+i)+j) = min(*(*(Array+i)+j),(*(*(Array+i)+k)+*(*(Array+k)+j)));
            }
        }
    }
}

#include<stdio.h>
void main(){
    int n;
    printf("\nEnter the number of vertices");
    scanf("%d",&n);

    int Array[n][n];
    printf("\nEnter the adjacency matrix of the weighted directed graph.:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Array[i][j]);
        }
    }

    //This will calculate the shortest distance between all pairs of vertices.
    Floyds(n,Array);

    printf("\nThe required matrix is:\n");
    //The matrix with the shortest distances between all the pairs of vertices is as follows.
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",Array[i][j]);
        }
        printf("\n");
    }
}
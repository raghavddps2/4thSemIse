/*

    @Author: Raghav Maheshwari.
    @Date: 26th May, 2019
    @Topic: Reachable Nodes using BFS.

*/
#include<stdio.h>
int n,AdjMatrix[100][100];
//The following will initialize the node as not visited and mark that it is not in the queue.
int queue[100],isVisited[100];
    //We define two arrays, one to keep track whether it is in the queue or not, secondly it is visited or not.
int r = -1; //pointer for putting the values of nodes that are reached.
int f =0; //for keeping track as to what all nodes all children covered.
  
void bfs(int vertex){
    for(int i=1;i<=n;i++){
        if(AdjMatrix[vertex][i] && !isVisited[i]){
            queue[++r] = i ;
        }
    }

    if(f<=r){
        isVisited[queue[f]] = 1; //mark that as visited.
        bfs(queue[f++]); 
    }
}

void main(){

    printf("\nEnter the number of nodes in the graph:\t");
    scanf("%d",&n);
    printf("\nEnter the Adjacency matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&AdjMatrix[i][j]);
        }
    }

    //The following will initialize the node as not visited and mark that it is not in the queue.
    //We define two arrays, one to keep track whether it is in the queue or not, secondly it is visited or not.

    for(int i=1;i<=n;i++){
        queue[i] = 0;
        isVisited[i] = 0;
    }
    int vertex; //this is the starting vertex.
    printf("\nEnter the starting node:\t");
    scanf("%d",&vertex);

    //This function wiill see as to what all nodes can be visited.
    bfs(vertex);
    int flag = 0; //flag to know if at least one node is visited.
    //Now whichever node is marked as visited wiill have isVisited avlue as 1.
    for(int i=1;i<=n;i++){
        if(isVisited[i]){
            flag = 1;
            break;
        }
    }

    if(flag){
        printf("\nThe nodes reachable from the given nodes are:\t");
        for(int i=1;i<=n;i++){
            if(isVisited[i]){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    else{
        printf("\nNo nodes are reachable from the given node.\n");
    }
}
#include<stdio.h>

int n;
int arr[20][20];
int visited[20] = {0};
int visitedOrder[20];
int count = 0;
void dfs(int i){
    count++;
    visited[i] = count;

    for(int v=1;v<=n;v++){
        if(arr[i][v] == 1 && visited[v] == 0){
            dfs(v);
        }
    }

}

void main(){

    printf("\nENter number of nodes");
    scanf("%d",&n);

    printf("\nEnter adjacenecy matrix");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nEnter source:\t");
    int source;
    scanf("%d",&source);

    dfs(source);

    for(int i=1;i<=n;i++){
        visitedOrder[visited[i]] = i;
    }
    printf("\nThe reachable nodes are:\t");
    for(int i=1;i<=n;i++){
        if(visited[i]){
             printf("%d ",visitedOrder[i]);
        }

    }
    printf("\n");

    //Now taking into care all.
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    for(int i=1;i<=n;i++){
        visitedOrder[visited[i]] = i;
    }
    //print DFS now.
    printf("\nThe DFS traversal is:\t");
    for(int i=1;i<=n;i++){
        printf("%d ",visitedOrder[i]);
    }
    printf("\n");
}
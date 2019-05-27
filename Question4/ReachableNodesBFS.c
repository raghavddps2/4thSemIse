#include<stdio.h>

int n;
int arr[20][20];
int visited[20] = {0};
int q[20] = {0};
int f = 0;
int r= 0;

void bfs(int i){

    for(int v=1;v<=n;v++){
        if(arr[i][v] == 1 && visited[v] == 0){
            q[r++] = v;
        }
    }

    if(f<r){
        if(!visited[q[f]]){
            visited[q[f]] = 1;
            printf("%d ",q[f]);
        }
        bfs(q[f++]);
    }
}

void main(){
    printf("\nEnter n");
    scanf("%d",&n);

    printf("\nEnter Adjacency matrix");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int source;
    printf("\nENter the source");
    scanf("%d",&source);
    visited[source] = 1;
    printf("BFS Traversal is: %d ",source);
    bfs(source);
    printf("\nnodes reachable from %d are: ",source);
	for(int i=1;i<=n;i++){
        if( i!=source && visited[i] == 1){
            printf("%d ",i);
        }
    }
    printf("\n");
}
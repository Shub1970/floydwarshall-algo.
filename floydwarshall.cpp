/* finding shortest path from each node to each node */
#include<iostream>
using namespace std;
#define V 4
#define INF 9999
int MIN(int a,int b){return(a<b)?a:b;}
int printdest(int graph[V][V]);
int floydwarshall(int graph[V][V]){
    int dest[V][V];
    /* creating duplicate of graph */
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dest[i][j]=graph[i][j];
            }}
    for(int k=0;k<V;k++){             /*node added in resoliving the distance b/w i,j */
        for(int i=0;i<V;i++){         /*consider i as a source */
            for(int j=0;j<V;j++){     /* consider j as a destination */
              if(dest[i][k]!=INF && dest[k][j]!=INF){
                  dest[i][j]=MIN(dest[i][k]+dest[k][j],dest[i][j]);
              }
            }
        }
    }
    return printdest(dest);

}
int printdest(int graph[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF)
               cout<<"INF"<<" ";
            else
               cout<<graph[i][j]<<"   ";
        }cout<<endl;
    }
}
int main(){
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    
 
    // Print the solution
    floydwarshall(graph);
    return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>
using namespace std;

struct Edge{
    int src;
    int dest;
    int weight;
};
struct Graph{
    int V;
    int E;
    Edge* edge;
};
Graph* CreateGraph(int v,int e){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->E = e;
    graph->V = v;
    graph->edge = (Edge*)malloc(e*sizeof(Edge));
    return graph;
}
void Print(int dist[],int n){
    for(int i = 0;i < n;++i){
        if(dist[i] == INT_MAX){
            cout<<"与节点"<<i<<"距离->无穷大"<<endl;
        }
        else{
            cout<<"与节点"<<i<<"距离->"<<dist[i]<<endl;
        }
    }
}
bool BellmanFord(Graph* graph,int src){
    int v = graph->V;
    int e = graph->E;
    int dist[v];
    for(int i = 0;i < v;++i){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    Edge edge;
    int a,b,weight;
    for(int i = 1;i < v;++i){
        for(int j = 0;j < e;++j){
            edge = graph->edge[j];
            a = edge.src;
            b = edge.dest;
            weight = edge.weight;
            if(dist[a] != INT_MAX && dist[a]+weight < dist[b]){
                dist[b] = dist[a]+weight;
            }
        }
    }
    bool Fu = false;
    for(int i = 0;i < e;++i){
        edge = graph->edge[i];
        a = edge.src;
        b = edge.dest;
        weight = edge.weight;
        if(dist[a] != INT_MAX && dist[a]+weight < dist[b]){
            Fu = true;
            break;
        }
    }

    Print(dist,v);
    return Fu;
}

int main(){
    int v = 5;
    int e = 8;

    Graph* graph = CreateGraph(v,e);
    cout<<"please input the number of edges"<<endl;
    int n=0;
    cin>>n;
    for(int i=0;i<n;i++){
         cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }
    BellmanFord(graph,0);
    return 0;
}

#include<iostream>
using namespace std;

struct graph{
    int v;
    int e;
    int **adjMatrix;
};

struct edge{
    int source;
    int dest;
};

struct graph *createGraph(int v){
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->v=v;
    g->e=0;
    //cout<<sizeof(int*)<<endl;
    g->adjMatrix = (int**)malloc(v*sizeof(int*));//rows
    cout<<g->adjMatrix<<endl;
    for(int i=0;i<v;i++){
        g->adjMatrix[i]=(int*)calloc(v,sizeof(int));
        cout<<&g->adjMatrix[i]<<" "<<g->adjMatrix[i]<<endl;
    }
    return g;
}

void insertEdge(struct graph *g,struct edge *e){
    if(e->source > g->v || e->dest > g->v){
        return;
    }
    if(g->adjMatrix[e->source][e->dest] != 1){
        g->adjMatrix[e->source][e->dest] = 1;
        g->e += 1;
    }
}

void removeEdge(struct graph *g,struct edge *e){
    if(e->source > g->v || e->dest > g->v){
        return;
    }
    if(g->adjMatrix[e->source][e->dest] != 0){
        g->adjMatrix[e->source][e->dest] = 0;
        g->e -= 1;
    }
}

void displayGraph(struct graph *g){
    for(int i=0;i<g->v;i++){
        for(int j=0;j<g->v;j++){
            cout<<g->adjMatrix[i][j]<<"-"<<&g->adjMatrix[i][j]<<"-"<<*(*(g->adjMatrix+i)+j)<<" ";
        }
        cout<<endl;
    }
}

struct edge newEdge(int s,int d){
    struct edge e;
    e.source=s;
    e.dest=d;
    return e;
}

int main(){
    //consider directed graph
    struct graph *g=createGraph(4);//0,1,2,3
    auto e1=newEdge(1,2);
    auto e2=newEdge(3,0);
    insertEdge(g,&e1);
    insertEdge(g,&e2);
    displayGraph(g);
    return 0;
}
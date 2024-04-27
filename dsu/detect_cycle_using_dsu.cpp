#include<iostream>
#include<vector>
using namespace std;

int findOp(int x,vector<int>& parent){
    //cout<<"find x"<<x<<" "<<parent[x]<<endl;
    if(x==parent[x]){ return x; }
    parent[x]=findOp(parent[x],parent);
    return parent[x];
}


void unionOp(int x,int y,vector<int>& parent,vector<int>& rank){
    //cout<<"union"<<endl;
    int x_par=findOp(x,parent);
    int y_par=findOp(y,parent);
    //cout<<"union-"<<x_par<<" "<<y_par<<endl;
    if(x_par==y_par){ return; }
    if(rank[x_par]<rank[y_par]){ parent[x_par]=y_par; }
    else if(rank[y_par]<rank[x_par]){ parent[y_par]=x_par; }
    else{ parent[x_par]=y_par; rank[y_par]++; }
}

int detectCycle(int V, vector<int>adj[]) //array of vectors
{
    // Code here
    vector<int>parent(V,0);
    vector<int>rank(V,0);
    for(int i=0;i<V;i++){
        parent[i]=i;
    }

    for(int i=0;i<V;i++){
        int i_par=findOp(i,parent);
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]>i){ // just to handle cases like 0--1 and 1--0 edges. the graph is undirected
                //cout<<adj[i][j]<<endl;
                int j_par=findOp(adj[i][j],parent);
                //cout<<i_par<<" "<<j_par<<endl;
                if(i_par==j_par){ 
                    //cout<<i<<" "<<adj[i][j]<<endl;
                    return 1; 
                }
                unionOp(i_par,j_par,parent,rank);
            }
        }
    }
    return 0;
}

int main(){
    vector<int>adj[5]{{3,2,4},{3},{0,4},{0,1},{0,2}};
    cout<<detectCycle(5,adj);
    return 0;
}
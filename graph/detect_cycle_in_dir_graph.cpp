#include<iostream>
#include<vector>
using namespace std;

bool dfs(int s,vector<int>graph[],vector<bool>& visited){
    if(visited[s]){return true;}
    
    visited[s]=true;
    for(int i=0;i<graph[s].size();i++){
        if(dfs(graph[s][i],graph,visited)==true){
            return true;
        }
    }
}

bool cycleInDirGraph(vector<int>graph[],int v){
    vector<bool>visited(v,false);
    return dfs(0,graph,visited);
}

int main(){
    const int v=4;
    vector<int>graph[v];
    graph[0]={1};
    graph[1]={2};
    graph[2]={3};
    graph[3]={1};
    cout<<cycleInDirGraph(graph,v);
    return 0;
}
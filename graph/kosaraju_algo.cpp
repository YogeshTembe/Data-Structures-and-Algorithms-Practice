#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>graph[],vector<bool>&visited,int u,int n,int& count){
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++){
        if(!visited[graph[u][i]]){
            dfs(graph,visited,graph[u][i],n,++count);
        }
    }
    cout<<u<<" "<<count<<endl; 
}

void kosarajuAlgo(vector<int>graph[],int n){
    vector<bool>visited(n,false);
    int count=1;
    dfs(graph,visited,1,n,count);
}

int main(){
    const int n=5;
    vector<int>graph[n];
    graph[0]={1};
    graph[1]={2,3};
    graph[2]={0};
    graph[3]={4};
    graph[4]={};
    kosarajuAlgo(graph,n);
    return 0;
}
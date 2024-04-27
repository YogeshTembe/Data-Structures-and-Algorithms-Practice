#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void shortestPathToEveryEdge(int source,vector<int>graph[],int nodes){
    queue<int>q;
    q.push(source);
    vector<int>dist(nodes,-1);
    dist[source]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            if(dist[graph[node][i]]==-1){
                dist[graph[node][i]] = dist[node]+1;
            }
            q.push(graph[node][i]);
        }
    }
    for(auto a:dist){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    const int v=4;
    vector<int>graph[v];
    graph[0]={1,2};
    graph[1]={2,3};
    graph[2]={3};
    graph[3]={2};
    shortestPathToEveryEdge(0,graph,4);
    return 0;
}
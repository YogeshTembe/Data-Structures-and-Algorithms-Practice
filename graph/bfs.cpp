#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

void bfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited){
    queue<int>q;
    q.push(2);
    visited[2]=true;
    while(!q.empty()){
        int ele=q.front();
        visited[ele]=true;
        cout<<ele<<" ";
        q.pop();
        for(int i=0;i<adj[ele].size();i++){
            if(!visited[adj[ele][i]]){
                visited[adj[ele][i]]=true;
                q.push(adj[ele][i]);
            }
        }
    }
}

int main(){
    unordered_map<int,vector<int>>adj;
    vector<bool>visited(4,false);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    bfs(adj,visited);
    return 0;
}
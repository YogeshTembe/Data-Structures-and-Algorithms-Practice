#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

void shortestDist(int src,unordered_map<int,vector<int>>& adj, vector<int>& dist){
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        //cout<<ele<<endl;
        for(int i=0;i<adj[ele].size();i++){
            if(dist[adj[ele][i]]==INT_MAX){
                dist[adj[ele][i]]=dist[ele]+1;
                q.push(adj[ele][i]);
            }
        }
    }
}

int main(){
    unordered_map<int,vector<int>>adj;
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    vector<int>dist(adj.size(),INT_MAX);
    shortestDist(0,adj,dist);
    for(auto d:dist){
        cout<<d<<" ";
    }
    return 0;
}
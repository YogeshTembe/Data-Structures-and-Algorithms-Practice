#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

//using recursion
void dfs(int node,unordered_map<int,vector<int>>& adj, vector<bool>& visited){
    cout<<node<<" ";
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i],adj,visited);
        }
    }
}

//using stack
void dfs2(unordered_map<int,vector<int>>& adj, vector<bool>& visited){
    stack<int>st;
    st.push(2);
    while(!st.empty()){
        int ele=st.top();
        visited[ele]=true;
        cout<<ele<<" ";
        st.pop();
        for(int i=0;i<adj[ele].size();i++){
            if(!visited[adj[ele][i]]){
                visited[adj[ele][i]] = true;
                st.push(adj[ele][i]);
            }
        }
    }
}

int main(){
    unordered_map<int,vector<int>>adj;
    vector<bool>visited(4,false);
    /*
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    dfs(2,adj,visited);
    cout<<endl;
    for(int i=0;i<4;i++){visited[i]=false;}
    dfs2(adj,visited);
    return 0;
}
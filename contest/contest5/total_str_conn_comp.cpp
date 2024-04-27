#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void dfs(unordered_map<int,vector<int>>&graph,int source,unordered_map<int,bool>&visited,vector<int>&s){
    for(auto a:graph[source]){
        if(!visited[a]){
            visited[a]=true;
            dfs(graph,a,visited,s);
        }
    }
    s.push_back(source);
}

void topologicalsort(unordered_map<int,vector<int>>&graph,vector<int>&s){
    unordered_map<int,bool>visited;
    for(auto it:graph){
        visited.insert({it.first,false});
    }
    visited[0]=true;
    dfs(graph,0,visited,s);
}

void transposegraph(unordered_map<int,vector<int>>&graph,unordered_map<int,vector<int>>&newgraph){
    for(auto it:graph){
        
    }
}

void dfs2(vector<vector<int>>&graph,int source,vector<bool>&visited){
    for(int i=0;i<graph[source].size();i++){
        if(graph[source][i]==1 && !visited[i]){
            visited[i]=true;
            dfs2(graph,i,visited);
        }
    }
}

int solve(int V, int E, vector<int> &a) {
    // code here
    // vector<vector<int>>graph(V, vector<int>(V,0));
    unordered_map<int,vector<int>>graph;
    int i=0;
    for(i=0;i<a.size()-1;i=i+2){
        graph[a[i]].push_back(a[i+1]);
    }

    // for(auto it:graph){
    //     cout<<it.first<<endl;
    // }
    vector<int>s;
    topologicalsort(graph,s);
    // for(auto v:s){cout<<v<<" ";}
    // cout<<endl;
    // for(auto v:s){cout<<v<<" ";}
    // cout<<endl;
    transposegraph(graph);
    
    // int res=0;
    // vector<bool>visited(graph.size(),false);
    // for(int i=s.size()-1;i>=0;i--){
        
    //     if(!visited[s[i]]){
    //         cout<<s[i]<<endl;
    //         res++;
    //         dfs2(graph,s[i],visited);
    //     }
    // }
    // return res;
    return 0;
}

int main(){
    vector<int>a{1,0,0,2,2,1,0,3,3,4};
    cout<<solve(5,5,a)<<endl;
    return 0;
}
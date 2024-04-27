#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isSafe(int curr,int next,unordered_map<int,int>& color){
    return (color[curr]!=color[next]);
}

bool solve(int curr,int prevcolor,unordered_map<int,vector<int>>& mp,unordered_map<int,int>& color,int m,int n,vector<bool>& visited){
    cout<<curr<<" "<<prevcolor<<" "<<m<<endl;
    // if(curr>=n){
    //     return (prevcolor<=m);
    // }
    if(prevcolor>m){
        return false;
    }
    // if(color[curr]!=-1){
    //     return true;
    // }

    color[curr]=prevcolor+1;
    bool safe=true;
    visited[curr]=true;

    for(auto node:mp[curr]){
        if(!visited[node] && isSafe(curr,node,color)){
            for(int i=prevcolor;i<=m;i++){
                return solve(node,i,mp,color,m,n,visited);
            }
        }
    }
    color[curr]=-1;
    return false;
}

bool graphColoring(bool graph[4][4], int m, int n) {
    // your code here
    unordered_map<int,vector<int>>mp;
    unordered_map<int,int>color;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1){
                //cout<<i<<" "<<j<<endl;
                mp[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        color.insert({i,-1});
    }
    // for(auto a:mp){
    //     cout<<a.first<<"-";
    //     for(auto b:a.second){ cout<<b<<" "; }
    //     //cout<<a.second.size();
    //     cout<<endl;
    // }
    return solve(0,0,mp,color,m,n,visited);
}

int main(){
    bool graph[4][4]{{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    cout<<graphColoring(graph,3,4);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int node,int n,bool graph[101][101],int col,vector<int>& color){
    for(int adj=0;adj<n;adj++){
        if(node!=adj && graph[node][adj]==1 && color[adj]==col){return false;}
    }
    return true;
}

bool solve(int node,int m,int n,bool graph[101][101],vector<int>& color){
    if(node==n){return true;}
    for(int i=1;i<=m;i++){
        if(isSafe(node,n,graph,i,color)){
            color[node]=i;
            if(solve(node+1,m,n,graph,color)==true){return true;}
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int>color(n,0);
    return solve(0,m,n,graph,color);
}

int main(){
    bool graph[101][101]{{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    cout<<graphColoring(graph,3,4)<<endl;
    return 0;
}
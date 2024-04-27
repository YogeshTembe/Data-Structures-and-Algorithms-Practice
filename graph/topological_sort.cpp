#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int findindegree(int node,vector<vector<int>>& adjMatrix){
    int indegree=0;
    for(int i=0;i<adjMatrix.size();i++){
        indegree += adjMatrix[i][node];
    }
    return indegree;
}

void topologicalSort(vector<vector<int>>& adjMatrix){
    vector<int>indegree(adjMatrix.size(),0);
    queue<int>q;
    //get nodes with zero indegree
    for(int i=0;i<adjMatrix.size();i++){
        indegree[i] = findindegree(i,adjMatrix);
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int ele = q.front();
        cout<<ele<<" ";
        q.pop();
        for(int i=0;i<adjMatrix[ele].size();i++){
            if(adjMatrix[ele][i] == 1){
                adjMatrix[ele][i] == 0;
                indegree[i] -= 1;
                if(indegree[i] == 0){
                    //cout<<"i-"<<i<<endl;
                    q.push(i);
                }
            }
        }
    }

}

int main(){
    vector<vector<int>>adjMatrix{{0,0,0,1,1,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,1,0,0,1},{0,0,0,0,0,1,1,1},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    topologicalSort(adjMatrix);
    return 0;
}
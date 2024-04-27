#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i,int j,int N,vector<int>maze[]){
    return (i<=N-1) && (j<=N-1) && (maze[i][j]>=1);
}

bool solveMaze(int i,int j,int N,vector<int> maze[],vector<vector<int>>& sol){
    cout<<i<<" "<<j<<endl;
    if(i==N-1 && j==N-1){
        sol[i][j]=1;
        return true;
    }
    if(isSafe(i,j,N,maze)){
        sol[i][j]=1;
        
        for(int k=1;k<=maze[i][j];k++){
            if(solveMaze(i,j+k,N,maze,sol)==true){return true;}//forward
            if(solveMaze(i+k,j,N,maze,sol)==true){return true;}//downward
        }
        sol[i][j]=0;
    }
    return false;
}

void printSol(vector<vector<int>>&sol){
    for(int i=0;i<sol.size();i++){
        for(int j=0;j<sol[i].size();j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}

void solve(int N, vector<int> maze[]){
    // write code here
    vector<vector<int>>sol(N,vector<int>(N,0));
    if(solveMaze(0,0,N,maze,sol)){
        printSol(sol);
        return;
    }
    cout<<"-1"<<endl;
}

int main(){
    /*
2 2 2 1 0 3
2 3 3 0 3 2
3 0 4 3 2 2
4 1 2 0 2 1
1 1 1 3 0 3
3 4 2 0 1 4
    */
   vector<int>maze[]{{2,2,2,1,0,3},{2,3,3,0,3,2},{3,0,4,3,2,2},{4,1,2,0,2,1},{1,1,1,3,0,3},{3,4,2,0,1,4}};
    solve(6,maze);
    // vector<int>maze[]{{2,1,0,0},{3,0,0,1},{0,1,0,1},{0,0,0,1}};
    // solve(4,maze);
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

const int N=9;

bool isSafe(int i,int j,int k,int grid[N][N]){
    for(int m=0;m<N;m++){ //check rows and column
        if(grid[i][m]==k || grid[m][j]==k){return false;}
        if(grid[3*(i/3)+m/3][3*(j/3)+m%3]==k){return false;}
    }
    return true;
}

bool SolveSudoku(int grid[N][N])  
{ 
    // Your code here
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            //cout<<i<<" "<<j<<endl;
            if(grid[i][j]==0){
                for(int k=1;k<=N;k++){
                    if(isSafe(i,j,k,grid)){
                        grid[i][j]=k;
                        if(SolveSudoku(grid)==true){return true;}
                        grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int grid[N][N] 
    {{3,0,6,5,0,8,4,0,0},
    {5,2,0,0,0,0,0,0,0},
    {0,8,7,0,0,0,0,3,1},
    {0,0,3,0,1,0,0,8,0},
    {9,0,0,8,6,3,0,0,5},
    {0,5,0,0,9,0,6,0,0},
    {1,3,0,0,0,0,2,5,0},
    {0,0,0,0,0,0,0,7,4},
    {0,0,5,2,0,6,3,0,0}};

    SolveSudoku(grid);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
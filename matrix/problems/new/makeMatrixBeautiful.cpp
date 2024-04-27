#include<iostream>
#include<vector>
using namespace std;

int findMinOpeartion(vector<vector<int>> matrix, int n)
{
    // code here 
    int maxR=INT_MIN,maxC=INT_MIN;
    vector<int>rowsums(n,0);
    vector<int>colsums(n,0);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            rowsums[i]+=matrix[i][j];
            colsums[j]+=matrix[j][i];
            maxR=max(maxR,rowsums[i]);
            maxC=max(maxC,colsums[j]);
        }
    }

    int rowans=0,colans=0;

    for(int i=0;i<rowsums.size();i++){
        rowans+=(maxR-rowsums[i]);
        colans+=(maxC-colsums[i]);
    }
    return max(rowans,colans);
} 

int main(){
    vector<vector<int>>matrix{{1, 2, 3},
              {4, 2, 3},
              {3, 2, 1}};
    cout<<findMinOpeartion(matrix,3);
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

//const int m=4;

void interchangeRows(int n, int m, vector<vector<int>>matrix)
{
    //code here
    for(int i=0;i<n/2;i++){
        for(int j=0;j<m;j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[abs(n-1-i)][j];
            matrix[abs(n-1-i)][j]=temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>>matrix{{1, 2, 3, 4},
             {5, 6, 7, 8},
             {9, 10, 11, 12},
             {13, 14, 15,16}};
    interchangeRows(4,4,matrix);
    return 0;
}
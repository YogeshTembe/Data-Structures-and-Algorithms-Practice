#include<iostream>
#include<vector>
using namespace std;

void reverseCol(vector<vector<int>> &matrix)
{
    int temp=0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size()/2;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][matrix[i].size()-1-j];
            matrix[i][matrix[i].size()-1-j]=temp;
        }
    }
}

int main(){
    vector<vector<int>>matrix{{ 1,  2,  3},{ 5,  6,  7},{11, 10,  9},{13, 14, 15}};
    reverseCol(matrix);
    for(auto a:matrix){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
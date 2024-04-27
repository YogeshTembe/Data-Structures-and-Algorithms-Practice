#include<iostream>
#include<vector>
using namespace std;

void exchangeColumns(vector<vector<int> > &matrix)
{
    // code here
    int temp=0;
    for(int i=0;i<matrix.size();i++){
        temp=matrix[i][0];
        matrix[i][0]=matrix[i][matrix[0].size()-1];
        matrix[i][matrix[0].size()-1]=temp;
    }
}

int main(){
    vector<vector<int>>matrix{{ 1,  2,  3},{ 5,  6,  7},{11, 10,  9},{13, 14, 15}};
    exchangeColumns(matrix);
    for(auto m:matrix){
        for(auto a:m){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
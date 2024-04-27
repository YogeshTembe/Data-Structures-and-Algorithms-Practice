#include<iostream>
#include<vector>
#include<set>
using namespace std;

void booleanMatrix(vector<vector<int>> &matrix)
{
    // code here 
    set<int>rows;
    set<int>cols;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==1){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (auto itr = rows.begin();itr != rows.end(); itr++)
    {
        for(int j=0;j<matrix[0].size();j++){
            matrix[*itr][j]=1;
        }
    }

    for (auto itr = cols.begin();itr != cols.end(); itr++){
        for(int j=0;j<matrix.size();j++){
            matrix[j][*itr]=1;
        }
    }
    
}

int main(){
    vector<vector<int>>matrix{{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}};
    booleanMatrix(matrix);

    for(auto r:matrix){
        for(auto a:r){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
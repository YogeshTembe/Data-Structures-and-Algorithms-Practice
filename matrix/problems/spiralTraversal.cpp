#include<iostream>
#include<vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    // code here 
    vector<int>res;
    int left=0;
    int right=c-1;
    int top=0;
    int bottom=r-1;
    while(left<=right && top<=bottom){
        //top row
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        //right column
        for(int i=top;i<=bottom;i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            //bottom row
            for(int i=right;i>=left;i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            //left column
            for(int i=bottom;i>=top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return res;
}

int main(){
    vector<vector<int>>matrix{{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12},{13, 14, 15,16}};
    auto res=spirallyTraverse(matrix,4,4);
    for(auto a:res){
        cout<<a<<" ";
    }
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void submatrix(vector<vector<int>>&temp,vector<vector<int>>&matrix,int p,int q,int n){
    int i=0,j=0;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            //cout<<matrix[r][c]<<endl;
            if(r!=p && c!=q){
                temp[i][j++]=matrix[r][c];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}

int determinantOfMatrix(vector<vector<int> > matrix, int n)
{
    // code here 
    int determinant=0;
    if(n==1){
        return matrix[0][0];
    }
    if(n==2){
        return (matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
    }
    vector<vector<int>>temp(n,vector<int>(n,0));
    int sign=1;
    
    for(int i=0;i<n;i++){
        submatrix(temp,matrix,0,i,n);
        determinant+=sign*matrix[0][i]*determinantOfMatrix(temp,n-1);
        sign=-sign;
    }
    return determinant;
}

int main(){
    vector<vector<int>>matrix{{1, 0, 2, -1},{3, 0, 0, 5},{2, 1, 4, -3},{1, 0, 5, 0}};
    cout<<determinantOfMatrix(matrix,matrix.size());
    return 0;
}
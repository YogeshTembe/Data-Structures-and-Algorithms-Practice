#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
{
    // code here
    vector<vector<int>>res;
    if(A[0].size()!=B.size()){
        return res;
    }

    for(int i=0;i<A.size();i++){
        vector<int>temp;
        for(int j=0;j<B[0].size();j++){
            temp.push_back(0);
        }
        res.push_back(temp);
    }

    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            int sum=0;
            for(int k=0;k<A[0].size();k++){
                sum=sum+A[i][k]*B[k][j];
            }
            res[i][j]=sum;
        }
    }
    return res;
}

int main(){
    vector<vector<int>>A{{4, 8},{0, 2},{1, 6}};
    vector<vector<int>>B{{5, 2},{9, 4}};
    auto res=multiplyMatrix(A,B);
    for(auto a:res){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
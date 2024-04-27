#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
{
    // code here
    vector<vector<int>>res;
    if(A.size()!=B.size() || A[0].size()!=B[0].size()){
        return res;
    }

    for(int i=0;i<A.size();i++){
        vector<int>temp;
        for(int j=0;j<A[0].size();j++){
            temp.push_back(A[i][j]+B[i][j]);
            //cout<<A[i][j]+B[i][j]<<endl;
        }
        res.push_back(temp);
    }
    return res;
}

int main(){
    vector<vector<int>>A{{1, 2, 3},{4, 5, 6}};
    vector<vector<int>>B{{1, 3, 3},{2, 3, 3}};
    auto res=sumMatrix(A,B);
    for(auto a:res){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}
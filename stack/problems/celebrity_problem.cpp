#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(M[a][b] && M[b][a]){
            continue;
        }
        else if(M[a][b]){
            st.push(b);
        }else if(M[b][a]){
            st.push(a);
        }
    }
    if(st.empty()){
        return -1;
    }
    int c=st.top();
    for(int i=0;i<n;i++){
        if(M[c][i]!=0){return -1;}
        if(c!=i && M[i][c]==0){return -1;}
    }
    return c;
}

int main(){
    vector<vector<int>>M{{0,1,0},{0,0,0}, {0,1,0}};
    cout<<celebrity(M,3);
    return 0;
}
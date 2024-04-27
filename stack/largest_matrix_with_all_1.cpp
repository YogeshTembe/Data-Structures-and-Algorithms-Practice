#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestRacArea2(vector<int>hist){
    stack<int>s;
    int res=INT_MIN;
    for(int i=0;i<hist.size();i++){
        while(!s.empty() && hist[s.top()]>=hist[i]){
            int topele=s.top();
            s.pop();
            int curr=s.empty()?i:(i-s.top()-1);
            res=max(res,hist[topele]*curr);
        }
        s.push(i);
    }
    //process remaining elements
    while(!s.empty()){
        int topele=s.top();
        s.pop();
        int curr=s.empty()?hist.size():(hist.size()-s.top()-1);
        res=max(res,hist[topele]*curr);
    }
    return res;
}

int LargestMatrixWithAllOnes(vector<vector<int>>matrix){
    vector<int>temp;
    for(int i=0;i<matrix.size();i++){
        temp.push_back(matrix[0][i]);
    }
    int res=largestRacArea2(temp);
    for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]==1){temp[j]++;}
            else{temp[j]=0;}
        }
        res=max(res,largestRacArea2(temp));
    }
    return res;
}

int main(){
    vector<vector<int>>matrix{{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout<<LargestMatrixWithAllOnes(matrix);
    return 0;
}
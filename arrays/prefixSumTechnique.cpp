#include<iostream>
#include<vector>
using namespace std;

vector<int> getQueries(vector<pair<int,int>>queries,int a[],int n){
    vector<int>sum;
    sum.push_back(a[0]);
    for(int i=1;i<n;i++){
        //cout<<a[i]<<endl;
        sum.push_back(sum[i-1]+a[i]);
    }
    vector<int>answer;
    for(int i=0;i<queries.size();i++){
        if(!((queries[i].first-1)<0)){
            answer.push_back(sum[queries[i].second]-sum[queries[i].first-1]);
        }else{
            answer.push_back(sum[queries[i].second]);
        }
    }
    return answer;
}

int main(){
    vector<pair<int,int>>queries{{0,2},{1,3},{2,6}};
    int a[]={2,8,3,9,6,5,4};
    auto ans=getQueries(queries,a,7);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
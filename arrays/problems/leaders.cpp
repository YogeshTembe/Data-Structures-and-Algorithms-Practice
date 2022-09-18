#include<iostream>
#include<vector>
using namespace std;

vector<int> leaders(int a[], int n){
    // Code here
    int max=-1;
    vector<int>res;
    for(int i=n-1;i>=0;i--){
        if(a[i]>=max){
            max=a[i];
            res.push_back(max);
        }
    }
    int temp=0;
    for(int i=0;i<int(res.size()/2);i++){
        //cout<<res[i]<<" "<<res[res.size()-1-i]<<endl;
        temp=res[i];
        res[i]=res[res.size()-1-i];
        res[res.size()-1-i]=temp;
    }
    return res;
}

int main(){
    // int a[]{16,17,4,3,5,2};
    // auto ans=leaders(a,6);
    int a[]{18,1,2,3,4,0};
    auto ans=leaders(a,6);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
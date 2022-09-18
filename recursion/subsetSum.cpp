#include<iostream>
#include<vector>
using namespace std;

void checkSum(vector<int>v,int sum, int currSum, int* res, int index){
    // if(sum==0 && v.size()>0){
    //     *res=1;
    //     return;
    // }
    
    if(index==v.size()){
        cout<<"sum-"<<currSum<<endl;
        if(sum==currSum){
            (*res)++;
        }
        return;
    }
    
    checkSum(v,sum,currSum+v[index],res,index+1);
    checkSum(v,sum,currSum,res,index+1);
}

int countSubsets(vector<int>v,int n,int sum){
    if(n==0){
        return (sum==0)?1:0;
    }
    return countSubsets(v,n-1,sum)+countSubsets(v,n-1,sum-v[n-1]);
}

int main(){
    //int res=0;
    vector<int>v{10,20,15};
    //checkSum(v,8,0,&res,0);
    //cout<<res;
    cout<<countSubsets(v,3,25);
    return 0;
}
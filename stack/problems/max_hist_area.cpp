#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    //find previous smaller elements
    stack<long long>pstack;
    vector<long long>ps;
    pstack.push(0);
    ps.push_back(-1);
    for(int i=1;i<n;i++){
        while(!pstack.empty() && arr[pstack.top()]>=arr[i]){
            pstack.pop();
        }
        if(pstack.empty()){ps.push_back(-1);}
        else{ps.push_back(pstack.top());}
        pstack.push(i);
    }

    // for(auto p:ps){
    //     cout<<p<<" ";
    // }
    // cout<<endl;

    //find next smaller elements
    stack<long long>nstack;
    vector<long long>ns;
    nstack.push(n-1);
    ns.push_back(n);
    for(int i=n-2;i>=0;i--){
        while(!nstack.empty() && arr[nstack.top()]>=arr[i]){
            nstack.pop();
        }
        if(nstack.empty()){ns.push_back(n);}
        else{ns.push_back(nstack.top());}
        nstack.push(i);
    }
    reverse(ns.begin(),ns.end());

    // for(auto n:ns){
    //     cout<<n<<" ";
    // }
    // cout<<endl;

    //actual impl
    long long res=LLONG_MIN;
    for(int i=0;i<n;i++){
        long long curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
}

int main(){
    long long arr[]{7,2,8,9,1,3,6,5};
    cout<<getMaxArea(arr,8);
    return 0;
}
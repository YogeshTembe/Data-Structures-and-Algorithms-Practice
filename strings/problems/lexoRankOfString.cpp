#include<iostream>
#include<vector>
using namespace std;

int fact(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int findRank(string s) 
{
    //Your code here
    //cout<<mul<<endl;
    vector<int>count(26,0);
    for(int i=0;i<s.length();i++){
        count[int(s[i]-'a')]++;
    }
    for(auto c:count){
        if(c>1){return 0;}
    }
    for(int i=1;i<count.size();i++){
        //cout<<count[i]<<" ";
        count[i]+=count[i-1];
    }
    //cout<<endl;
    // for(int i=1;i<count.size();i++){
    //     cout<<count[i]<<" ";
    // }
    // cout<<endl;

    int n = s.length();
    vector<long long> fact(n);
    fact[0] = 1;
    int p=1000000007;
    for(int i=1; i<n; i++) fact[i]=(fact[i-1]*i)%p;

    long long res=1;
    for(int i=0;i<s.length();i++){
        res=res+(((count[int(s[i]-'a')]-1)%1000000007)*fact[n-i-1])%1000000007;
        cout<<(count[int(s[i]-'a')]-1)<<" "<<res<<endl;
        //reduce its count from all the counts ahead of s[i]
        for(int j=int(s[i]-'a');j<26;j++){
            count[j]--;
        }
    }
    return res%1000000007;
}

int main(){
    cout<<findRank("tucmhpqzwrgeixkjnaslvyfdbo")<<endl;
    cout<<findRank("aaaa")<<endl;
    return 0;
}
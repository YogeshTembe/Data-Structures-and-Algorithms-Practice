#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int factorial(int num){
    if(num==0 || num==1){
        return 1;
    }
    int ans=1;
    for(int i=1;i<=num;i++){
        ans*=i;
        //cout<<"-"<<ans<<endl;
    }
    return ans;
}

int lexicographicStr(string s){
    vector<int>lowcharcount(s.length(),0);
    int c=1;
    int mx=int(s[s.length()-1]-'A');
    for(int i=s.length()-2;i>=0;i--){
        cout<<mx<<" "<<int(s[i]-'A')<<endl;
        if(int(s[i]-'A')>=mx){
            lowcharcount[i]=c;
            mx=int(s[i]-'A');
        }else{
            lowcharcount[i]=lowcharcount[i+1];
        }
        c++;
    }
    for(auto l:lowcharcount){cout<<l<<" ";}
    cout<<endl;
    int ans=0;
    for(int i=0;i<s.length();i++){
        cout<<lowcharcount[i]<<" "<<s.length()-1-i<<endl;
        ans=ans+(lowcharcount[i]*factorial(s.length()-1-i));
        cout<<ans<<endl;
    }
    return ans+1;
}

int main(){
    //cout<<factorial(5)<<endl;
    cout<<lexicographicStr("BAC");
    return 0;
}
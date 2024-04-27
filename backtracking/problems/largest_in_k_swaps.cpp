#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int idx,int currk,string str,string& res){
    res=max(res,str);
    //cout<<idx<<" "<<currk<<" "<<str<<" "<<res<<endl;
    if(currk==0){return;}
    if(idx==str.length()){return;}

    char ch=*max_element(res.begin()+idx,res.end());
    if(ch>str[idx]){
        for(int j=idx+1;j<str.length();j++){
            swap(str[idx],str[j]);
            solve(idx+1,currk-1,str,res);
            swap(str[idx],str[j]);
        }
    }else{
        solve(idx+1,currk,str,res);
    }
}

string findMaximumNum(string str, int k){
    // code here.
    string res=str;
    solve(0,k,str,res);
    //solve2(str,res,k,0);
    return res;
}

int main(){
    cout<<findMaximumNum("1234567",4)<<endl;
    cout<<findMaximumNum("3435335",3)<<endl;
    /*
    2
1034*/
    cout<<findMaximumNum("1034",2)<<endl;
    /*4
61892795431*/
cout<<findMaximumNum("61892795431",4)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> res;

void stringSubsets(string s,string curr,int index){
    if(index==s.length()){
        //cout<<curr<<" ";
        res.push_back(curr);
        return;
    }
    stringSubsets(s,curr+s[index],index+1);
    stringSubsets(s,curr,index+1);
}

vector<string> powerSet(string s)
{
   //Your code here
    stringSubsets(s,"",0);
    return res;
}


int main(){
    auto v=powerSet("abc");
    //cout<<"yes";
    for(auto i:v){
        cout<<i<<endl;
        cout<<"here"<<endl;
    }
    return 0;
}
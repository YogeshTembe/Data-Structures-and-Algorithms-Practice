#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> generate(int N)
{
	// Your code here
    queue<string>q;
    q.push("1");
    string bin="";
    while(N){
        if(N%2==0){
            bin+="0";
        }else{
            bin+="1";
        }
        N=N/2;
    }
    reverse(bin.begin(),bin.end());
    vector<string>res;
    while(q.front()!=bin){
        string a=q.front();
        q.pop();
        res.push_back(a);
        q.push(a+"0");
        q.push(a+"1");
    }
    res.push_back(q.front());
    return res;
}

int main(){
    auto res=generate(2);
    for(auto r:res){
        cout<<r<<" ";
    }
    return 0;
}
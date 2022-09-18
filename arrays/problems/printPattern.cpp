#include<iostream>
#include<vector>
using namespace std;

//Task was to solve this without using any loop, so used recursion

vector<int> res;
int count=0;
int flag=0;
vector<int> pattern(int N){
    // code here
    if(N<=0){
        flag=1;
    }
    if(count==0){
        if(N%5==0){count=(2*(N/5))+1;}
        else{count=2*((N/5)+1)+1;}
    }
    if(res.size()==count){
        return res;
    }
    if(flag==0){
        res.push_back(N);
        return pattern(N-5);
    }
    else if(flag==1){
        res.push_back(N);
        return pattern(N+5);
    }
    return res;
}

int main(){
    pattern(16);
    for(auto i:res){cout<<i<<" ";}
    return 0;
}
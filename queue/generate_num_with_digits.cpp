#include<iostream>
#include<queue>
using namespace std;

void generateNumsWithDigits(int n){
    queue<string>q;
    int count=0;
    q.push("5");
    q.push("6");
    for(int i=0;i<n;i++){
        string curr=q.front();
        cout<<curr<<" ";
        q.pop();
        q.push(curr+"5");
        q.push(curr+"6");
    }
}

int main(){
    generateNumsWithDigits(10);
    return 0;
}
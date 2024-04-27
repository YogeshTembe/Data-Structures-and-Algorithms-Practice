#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s,int mid){
    if(s.size()==mid){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    solve(s,mid);
    s.push(temp);
}
//Function to delete middle element of a stack.
void deleteMid(stack<int>&s, int sizeOfStack)
{
    // code here.. 
    int mid=ceil((sizeOfStack+1)/2);
    solve(s,mid);
}

int main(){
    return 0;
}
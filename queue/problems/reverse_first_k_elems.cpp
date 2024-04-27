#include<iostream>
#include<queue>
using namespace std;

void reverse(queue<int>& q,int count,int k){
    if(count>=k || q.empty()){
        return;
    }
    int ele=q.front();
    q.pop();
    reverse(q,count+1,k);
    q.push(ele);
}

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    reverse(q,0,k);
    int i=0;
    while(i<(q.size()-k)){
        q.push(q.front());
        q.pop();
        i++;
    }
    return q;
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);q.push(3);q.push(4);q.push(5);
    auto newq=modifyQueue(q,3);
    while(!newq.empty()){
        cout<<newq.front()<<" ";
        newq.pop();
    }
    return 0;
}
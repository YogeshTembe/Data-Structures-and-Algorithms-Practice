#include<iostream>
#include<stack>
#include<set>
using namespace std;

class myStack{
    private:
    stack<int>s;
    set<int>eles;
    public:
    myStack(){
    }

    void push(int ele){
        eles.insert(ele);
        s.push(ele);
    }

    void pop(){
        eles.erase(s.top());
        s.pop();
    }

    int top(){
        return s.top();
    }

    int getMin(){
        // for(auto it=eles.begin();it!=eles.end();it++){
        //     cout<<*it<<" ";
        // }
        // cout<<endl;
        return *eles.begin();
    }
};

int main(){
    myStack ms;
    ms.push(34);
    ms.push(4);
    ms.push(6);
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    return 0;
}
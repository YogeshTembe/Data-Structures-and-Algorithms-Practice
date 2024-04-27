#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void printstack(stack<char>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

string removePair(string str)
{
    // Your code here
    stack<char>st;
    st.push(str[0]);
    for(int i=1;i<str.length();i++){
        // cout<<"str-"<<str[i]<<endl;
        // cout<<"---"<<endl;
        // printstack(st);
        if(st.empty()){
            st.push(str[i]);
        }else if(st.top()==str[i]){
            st.pop();
        }else{
            st.push(str[i]);
        }
    }
    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    cout<<removePair("aaabbaaccd")<<endl;
    cout<<removePair("aaaa")<<endl;
    return 0;
}
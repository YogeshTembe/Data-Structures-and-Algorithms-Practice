#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParenthesis(string str){
    stack<char>st;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            st.push(str[i]);
        }else{
            if(str[i]==')'){
                if(st.top()=='('){st.pop();}
                else{return false;}
            }
            if(str[i]==']'){
                if(st.top()=='['){st.pop();}
                else{return false;}
            }
            if(str[i]=='}'){
                if(st.top()=='{'){st.pop();}
                else{return false;}
            }
        }
    }
    return st.empty();
}

int main(){
    cout<<isBalancedParenthesis("((())")<<endl;
    return 0;
}
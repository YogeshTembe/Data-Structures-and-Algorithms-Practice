#include<iostream>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool stackTopOperatorGreater(char ele,char top,unordered_map<char,pair<int,string>>& mp){
    if(mp[ele].first > mp[top].first || (mp[ele].first==mp[top].first && mp[ele].second=="lr")){
        return false;
    }
    return true;
}


bool isGreater(char input,char stackTop,unordered_map<char,pair<int,string>>& mp){
    if(mp[input].first > mp[stackTop].first || (mp[input].first==mp[stackTop].first && mp[input].second=="lr")){
        return true;
    }
    return false;
}

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^' || c==')');
}

string convertInfixToPrefix(string infix){
    unordered_map<char,pair<int,string>>mp;
    mp.insert({')',{0,"lr"}});
    mp.insert({'+',{1,"lr"}});
    mp.insert({'-',{1,"lr"}});
    mp.insert({'*',{2,"lr"}});
    mp.insert({'/',{2,"lr"}});
    mp.insert({'^',{3,"rl"}});

    stack<char>operators;
    string prefix="";
    for(int i=infix.size()-1;i>=0;i--){
        //cout<<infix[i]<<" "<<prefix<<endl;
        if(isOperator(infix[i])){
            if(operators.empty()){
                operators.push(infix[i]);
            }
            else if(infix[i]==')'){//right bracket
                operators.push(infix[i]);
            }
            else if(!stackTopOperatorGreater(infix[i],operators.top(),mp)){
                operators.push(infix[i]);
            }else{
                char top=operators.top();
                while(!operators.empty() && stackTopOperatorGreater(infix[i],top,mp)){
                    top=operators.top();
                    if(top!=')'){
                        prefix+=top;
                    }
                    operators.pop();
                }
                operators.push(infix[i]);
            }
        }else if(infix[i]=='('){ //left bracket
            while(operators.top()!=')'){
                if(operators.top()!=')'){
                    prefix+=operators.top();
                }
                operators.pop();
            }
            operators.pop();
        }else{//right bracket and operands
            prefix+=infix[i];
        }
    }
    while(!operators.empty()){
        prefix+=operators.top();
        operators.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main(){
    cout<<convertInfixToPrefix("x+y*z")<<endl;
    cout<<convertInfixToPrefix("x^y^z")<<endl;
    cout<<convertInfixToPrefix("(x+y)*(z+w)")<<endl;
    return 0;
}
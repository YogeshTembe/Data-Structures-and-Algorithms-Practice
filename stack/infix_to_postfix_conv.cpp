#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

bool stackTopOperatorGreater(unordered_map<char,pair<int,string>>& pa,char top,char ele){
    if(pa[top].first>pa[ele].first || (pa[top].first==pa[ele].first && pa[ele].second=="lr")){
        return true;
    }
    return false;
}

string conversion(string infix){
    string postfix="";
    
    unordered_map<char,pair<int,string>>pa;//precedence and associativity
    pa.insert({'(',{0,"lr"}});
    pa.insert({'+',{1,"lr"}});
    pa.insert({'-',{1,"lr"}});
    pa.insert({'*',{2,"lr"}});
    pa.insert({'/',{2,"lr"}});
    pa.insert({'^',{3,"rl"}});
    //dont have to worry about left bracket because it should never come in comparison as it will be removed by corresponding right bracket

    stack<char>s;
    int i=0;
    while(i<infix.length()){
        cout<<infix[i]<<" "<<postfix<<endl;
        if(infix[i]=='('){ //left parenthesis operator
            s.push(infix[i]);
        }else if(infix[i]==')'){ //right parenthesis operator
            while(!s.empty()){
                if(s.top()=='('){
                    s.pop();
                    break;
                }
                postfix+=s.top();
                s.pop(); 
            }
        }else if(isOperator(infix[i])){ //operator
            while(!s.empty() && stackTopOperatorGreater(pa,s.top(),infix[i])){
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
        }else{ //operand
            //cout<<infix[i]<<endl;
            postfix+=infix[i];
        }
        i++;
    }
    while(!s.empty()){
        if(s.top()!='('){
            postfix+=s.top();
        }
        s.pop();
    }
    return postfix;
}

int main(){
    cout<<conversion("a+b*(c^d-e)^(f+g*h)-i");
    return 0;
}
#include<iostream>
#include <stack>
#include<vector>
#include<string>
#include <cmath>
using namespace std;

bool isOperator(string s){
    return (s=="+" || s=="-" || s=="*" || s=="/" || s=="^");
}

int evaluatePostfix(string postfix){
    std::vector<std::string> words;
    std::string word;
    stack<int>s;
    for(int i=0;i<postfix.length();i++){
        if(postfix[i]==' '){
            words.push_back(word);
            word="";
        }else{
            word+=postfix[i];
        }
    }
    words.push_back(word);
    for(int i=0;i<words.size();i++){
        //cout<<words[i]<<endl;
        if(isOperator(words[i])){
            int num2=s.top();
            s.pop();
            int num1=s.top();
            s.pop();
            if(words[i]=="+"){s.push(num1+num2);}
            else if(words[i]=="-"){s.push(num1-num2);}
            else if(words[i]=="*"){s.push(num1*num2);}
            else if(words[i]=="/"){s.push(num1/num2);}
            else if(words[i]=="^"){s.push(pow(num1,num2));}
        }else{
            s.push(stoi(words[i]));
        }
    }
    return s.top();
}

int main(){
    cout<<evaluatePostfix("10 2 * 3 +")<<endl;
    cout<<evaluatePostfix("10 2 3 ^ ^")<<endl;
    return 0;
}
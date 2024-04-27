#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

string removeConsecutiveDuplicates(string s)
{
    // Your code here
    stack<char>st;
    st.push(s[0]);
    for(int i=1;i<s.length();i++){
        if(s[i]!=st.top()){
            st.push(s[i]);
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
    cout<<removeConsecutiveDuplicates("aaaaaabaabccccccc")<<endl;
    cout<<removeConsecutiveDuplicates("abbccbcd")<<endl;
    return 0;
}
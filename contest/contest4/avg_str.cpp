#include<iostream>
#include<cmath>
using namespace std;

int avgOfString(string s)
{
    int res=0;
    for(int i=0;i<s.length();i++){
        res = res + int(s[i]);
    }
    return floor(res/s.length());
}

int main(){
    cout<<avgOfString("abcd")<<endl;
    return 0;
}
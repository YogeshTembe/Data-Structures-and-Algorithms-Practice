#include<iostream>
using namespace std;

int strstr(string s, string x)
{
     //Your code here
    int i=0;
    int j=0;
    while(i<s.length()){
        int j=0;
        int k=i;
        cout<<s[k]<<" "<<x[j]<<endl;
        while(k<s.length() && s[k]==x[j]){
            cout<<"m"<<endl;
            k++;
            j++;
        }
        if(j==x.length()){
            return i;
        }
        i++;
    }
    return -1;
}

int main(){
    //abcabcabcd abcd
    cout<<strstr("abcabcabcd","abcd")<<endl;
    return 0;
}
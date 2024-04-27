#include<iostream>
#include<vector>
using namespace std;

int findSum(string str)
{
    // Your code here
    int res=0;
    int su=0;
    for(int i=0;i<str.length();i++){
        su=0;
        cout<<str[i]<<endl;
        while(i<str.length() && str[i]>=48 && str[i]<=57){
            su=su*10+int(str[i]-'0');
            i++;
        }
        if(i<str.length() && str[i]>57){
            res+=su;
            cout<<i<<" "<<res<<endl;
        }
    }
    if(str[str.length()-1]>=48 && str[str.length()-1]<=57){
        res+=su;
    }
    return res;
}

int main(){
    // cout<<findSum("1abc23")<<endl;
    // cout<<findSum("geeks4geeks456")<<endl;
    cout<<findSum("sdjvuvsd3dv4d32v")<<endl;
    return 0;
}
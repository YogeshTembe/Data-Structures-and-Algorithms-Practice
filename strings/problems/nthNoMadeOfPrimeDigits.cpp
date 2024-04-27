#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int primeDigits(int n)
{
    //code here
    vector<char>table{'2','3','5','7'};
    string temp;
    while(n>0){
        int rem=n%4;
        if(rem==0){
            rem=4;
            n--;
        }
        temp=temp+table[rem-1];
        n=n/4;
    }
    //cout<<temp<<endl;
    reverse(temp.begin(),temp.end());
    return stoi(temp);
}

int main(){
    cout<<primeDigits(16)<<endl;
    return 0;
}
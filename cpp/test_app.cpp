#include<iostream>
#include<string>
using namespace std;


int main(){
    int n=1367;
    string str="";
    int j=97;
    for(int i=0;i<n;i++){
        if(j==122){j=97;}
        str+=char(j);
        j++;
    }
    cout<<str<<endl;
    return 0;
}
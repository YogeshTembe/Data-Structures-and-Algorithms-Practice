#include<iostream>
using namespace std;

int main(){
    int a=5;
    char *cptr=static_cast<char*>(&a);
    cout<<*cptr<<endl;
    return 0;
}
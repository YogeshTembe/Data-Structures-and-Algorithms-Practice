#include<iostream>
using namespace std;

int main(){
    //cout<<"hello"<<endl;
    int num=5;
    cout<<num<<endl;
    int *ptr=new (&num) int(4);
    cout<<num<<" "<<*ptr<<endl;
    return 0;
}
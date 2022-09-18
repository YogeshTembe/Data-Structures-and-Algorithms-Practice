#include<iostream>
using namespace std;

void TOH(int n, string A, string B, string C){
    if(n==1){
        cout<<"Move disc 1 from "<<A<<" to "<<C<<endl;
        return;
    }
    TOH(n-1,A,C,B);
    cout<<"Move disc "<<n<<" from "<<A<<" to "<<C<<endl;
    TOH(n-1,B,A,C);
}

int main(){
    TOH(3,"A","B","C");
    return 0;
}
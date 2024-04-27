#include <iostream>
using namespace std;

int main(){
    const volatile int test=10;
    int *ptr=(int*)&test;
    *ptr=100;
    cout<<test<<endl;
    return 0;
}
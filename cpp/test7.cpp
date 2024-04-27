// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    const int a=45;
    int *p=(int*)&a;
    cout<<*p<<endl;
    *p=56;
    cout<<a<<endl;
    return 0;
}
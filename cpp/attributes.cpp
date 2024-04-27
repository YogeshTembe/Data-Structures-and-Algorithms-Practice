#include<iostream>
using namespace std;

// [[noreturn]] void func1(){
//     cout<<"inside func1"<<endl;
// }

void func2(){
    cout<<"inside func2"<<endl;
}

[[deprecated("msg")]] void func3(){
    cout<<"inside func3"<<endl;
}

int main(){
    func3();
    return 0;
}
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class test{
  public:
  test(){cout<<"test constr"<<endl;}
};

int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    test *t1=new test;
    test *t2=new test();
    int *p1=new int;
    int *p2=new int();
    cout<<*p1<<" "<<*p2<<endl;
    return 0;
}
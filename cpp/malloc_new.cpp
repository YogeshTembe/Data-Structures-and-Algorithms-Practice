#include<iostream>
using namespace std;

class test{
    public:
    int a;
    float b;
    test(){
        cout<<"test constructor"<<endl;
        a=5;
        b=4.5f;
    }
};

int main(){
    cout<<"call1"<<endl;
    test *t1=(test*)malloc(sizeof(test));
    cout<<"call2"<<endl;
    test *t2=new test();
    cout<<t1->a<<" "<<t2->a<<endl;
    cout<<t1->b<<" "<<t2->b<<endl; 
    return 0;
}
#include<iostream>
using namespace std;

class test{
    public:
    int a;
    explicit test(int a){
        cout<<"test constructor called"<<endl;
        this->a=a;
    }

    explicit operator int(){
        cout<<"operator int called"<<endl;
        return a;
    }
};

void func(test t){
    cout<<t.a<<endl;
}

int main(){
    test t1{3};
    // test t2=static_cast<test>(4);
    // t2=static_cast<test>(7);
    // cout<<"t2.a-"<<t2.a<<endl;
    // func(t1);

    int a=static_cast<int>(t1);

    return 0;
}
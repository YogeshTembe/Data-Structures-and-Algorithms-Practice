#include<iostream>
using namespace std;

class base{
    public:
    virtual void show(){
        cout<<"here"<<endl;
    }
};

class child1:public base{

};

class child2:public base{

};

int main(){
    base *b1=new child1();
    const type_info &base_ti=typeid(base);
    const type_info &child1_ti=typeid(child1);
    cout<<base_ti.name()<<" "<<child1_ti.name()<<endl;
    const type_info &ti=typeid(b1);
    cout<<ti.name()<<endl;
    const type_info &ti2=typeid(*b1);
    cout<<ti2.name()<<endl;
    base *b2=new base();
    const type_info &ti3=typeid(*b2);
    cout<<ti3.name()<<endl;

    unsigned int somenum=9;
    const type_info &tint=typeid(somenum);
    cout<<tint.name()<<endl;
    return 0;
}
#include<iostream>
using namespace std;

class A{
    public:
    string name;
    A(string name){
        cout<<"A constructor"<<endl;
        this->name=name;
    }
    virtual void show(){}
};

class B: virtual public A{
    public:
    string company;
    B(string company):A("namefromB"){
        cout<<"B constructor"<<endl;
        this->company=company;
    }
};

class C: virtual public A{
    public:
    string pet;
    C(string pet):A("namefromC"){
        cout<<"C constructor"<<endl;
        this->pet=pet;
    }
};

class D:public B, public C{
    public:
    string address;
    D(string address):B("companyfromD"),C("petfromD"),A("namefromD"){
        cout<<"D constructor"<<endl;
        this->address=address;
    }
};

int main(){
    // D d("rit");
    // //cout<<d.name<<endl;
    // A *aptr=new D("iop");
    // D *dptr=dynamic_cast<D*>(aptr);
    // cout<<dptr->name<<" "<<dptr->address<<endl;
    B bobj("xyz");
    C cobj("test");
    A *aptr=&bobj;
    C *cptr=dynamic_cast<C*>(aptr);
    if(cptr!=nullptr){
        cout<<"cast done"<<endl;
    }else{
        cout<<"cast not done"<<endl;
    }
    // if(typeid(aptr)==typeid(C)){
    //     C *cptr=static_cast<C*>(aptr);
    //     cout<<"cast done"<<endl;
    // }else{
    //     cout<<"cast not done"<<endl;
    // }

    return 0;
}
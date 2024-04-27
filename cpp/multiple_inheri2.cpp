#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"A constructor"<<endl;
    }
    void somefunc(){
        cout<<"somefunc of A"<<endl;
    }
};

class B{
    public:
    B(){
        cout<<"B constructor"<<endl;
    }
    void somefunc(){
        cout<<"somefunc of B"<<endl;
    }
};

class C:public A,public B{
    public:
    C(){
        cout<<"C constructor"<<endl;
    }
};

// int test(int a){
//     return a+1;
// }

// float test(int a){
//     return a+1;
// }

int main(){
    C cobj;
    cobj.A::somefunc();
    cobj.B::somefunc();
    int arr[]{3,4,5};
    int a=8;
    int *ptr=&a;
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<" "<<sizeof(a)<<endl;
    float f1{3.4f};
    int i1=f1;
    //cout<<i1<<endl;
    return 0;
}
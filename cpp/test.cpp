#include <iostream>
using namespace std;

class A{
    public:
    int x;
    float f;
    A(){cout<<"A constru"<<endl;}
    // A()=default;
};

int main(){
    // int *p1=new int;
    // cout<<*p1<<endl;

    // int *p2=new int();
    // cout<<*p2<<endl;

    A *aptr = new A;
    cout<<aptr->x<<" "<<aptr->f<<endl;
    A *aptr2 = new A();
    cout<<aptr2->x<<" "<<aptr2->f<<endl;
    A aobj{};
    cout<<aobj.x<<" "<<aobj.f<<endl;
    return 0;
}
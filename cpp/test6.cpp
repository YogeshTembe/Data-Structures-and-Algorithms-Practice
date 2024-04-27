// C++ program to demonstrate 
// static_cast in case of 
// private inheritance
#include <iostream>
using namespace std;

class Base 
{
    public:
    int a=5;
    Base(){
        cout<<"base constructor"<<endl;
    }
    virtual void show();
    
};

class Derived: public Base 
{ 
// Inherited private/protected 
// not public
 public:
    int b=6;
    Derived(){
        cout<<"derived constructor"<<endl;
    }
    void show() override{
        cout<<Base::a<<" "<<b<<endl;
    }
};

// Driver code
int main()
{ 

//d1.show();
// Implicit type cast allowed
// Base* b1 = (Base*)(&d1);

// Derived d1;
// //upcasting
// // Base* b2 = static_cast<Base*>(&d1);
// Base* b2 = &d1;
// cout<<b2->a<<endl;
// b2->show();

Base *baseobj=new Derived();
//downcasting
Derived *dptr=dynamic_cast<Derived*>(baseobj);
dptr->show();

return 0;
}

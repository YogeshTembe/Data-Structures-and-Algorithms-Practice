#include<iostream>
using namespace std;

class Bix{
    public:
    int x,y;

    Bix(int x):x(x){}
    
    void display(){
        cout<<x<<endl;
    }
    //static void MyFunction(){}
};

int main(){
    //void(*ptr)() = &Bix::MyFunction;
    Bix bix(46);
    bix.display();
    int *p = (int*)&bix;
    *p=23;
    bix.display();
    return 0;
}
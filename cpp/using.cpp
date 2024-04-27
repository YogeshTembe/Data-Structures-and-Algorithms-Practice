#include <iostream>
using namespace std;

class Base {
public:
	int x;
    string str;
	// parameterized constructor
	Base(int a) : x(a){};
	Base(string str):str(str){}
};

class Derived : public Base {
public:
	int y;
	using Base::Base;
	Derived(int x,int y):Base(x){
	    this->y=y;
	}
};

int main()
{

	Derived d(42);
	//d.y = 12;
	cout << d.x << " " << d.y << '\n';
    Derived d1(34,56);
    cout << d1.x << " " << d1.y << '\n';
    Derived d2("rt");
    cout << d2.x << " " << d2.y << " "<<d2.str<<'\n';
	return 0;
}

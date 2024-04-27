// CPP code to illustrate the pointer reinterpret
#include <iostream>
#include<vector>
using namespace std;

class A {
public:
    int a=5;
    A(){
        cout<<"constructor A"<<endl;
    }
	void fun_a()
	{
		cout << " In class A\n";
	}
};

class B {
public:
    B(){
        cout<<"constructor B"<<endl;
    }
	void fun_b()
	{
		cout << " In class B\n";
	}
};

int main()
{
	// creating object of class B
	B* x = new B();

	// converting the pointer to object
	// referenced of class B to class A
	A* new_a = reinterpret_cast<A*>(x);

	// accessing the function of class A
	new_a->fun_a();
    cout<<new_a->a<<endl;

	const int n=3;
	int arr[n];
	int arr3[n];
	arr[0]=45;
	//arr3=arr;
	
	vector<int>vec(4);
	vector<int>v2(4);
	v2=vec;
	vec[0]=45;
	cout<<v2[0]<<endl;
	return 0;
}

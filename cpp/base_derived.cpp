#include<iostream>
using namespace std;

class duck{
    public:
    string name;
    //duck(){}
    duck(string n){}
    void swim(){
        cout<<"duck swim"<<endl;
    }
};

class donaldduck: public duck{
    public:
    string name;
    //using duck::duck;
    donaldduck(string n){}
    void swim(string s){
        cout<<"donald duck swim-"<<s<<endl;
        duck::swim();
    }
};

int main(){
    donaldduck d("uiao");
    cout<<"here-"<<d.name<<endl;
    d.swim("mm");
    return 0;
}
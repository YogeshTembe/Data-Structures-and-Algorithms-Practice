#include<iostream>
#include<vector>
using namespace std;

class test{
    public:
    string name;
    int pos;
    test(string n,int p):name(n),pos(p){
        cout<<"test constructor"<<endl;
    }
    test(const test& t1){
        cout<<"test copy constructor"<<endl;
        this->name=t1.name;
        this->pos=t1.pos;
    }
    test(test&& t1) noexcept{
        cout<<"test move constructor"<<endl;
    }
};

int main(){
    vector<test>vec;
    
    test t1{"t1",1};
    vec.push_back(t1);
    
    cout<<"--here"<<endl;
    vec.emplace_back("t2",2);

    cout<<"--here2"<<endl;
    //test t3{"t3",1};
    vec.emplace_back("t3",3);
    //vec.emplace_back("t3",3);
    return 0;
}
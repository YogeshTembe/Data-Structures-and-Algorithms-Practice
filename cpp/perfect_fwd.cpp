#include<iostream>
using namespace std;

class test{
    public:
    string name;
    test(){
        cout<<"default test constructor"<<endl;
    }
    test(string name){
        cout<<"test constructor"<<endl;
        this->name=name;
    }
    test(test &t){
        cout<<"test copy constructor"<<endl;
        this->name=t.name;
    }
    test(test &&t){
        cout<<"test move constructor"<<endl;
        this->name=t.name;
        t.name="moved";
    }
    test& operator=(test &t){
        cout<<"test assignment operator name-"<<this->name<<endl;
        return t;
    }
    ~test(){
        cout<<"test destructor name-"<<this->name<<endl;
    }
};

class animal{
    public:
    test tobj;
    //template<typename t1>
    animal(test &t):tobj{t}{ //std::forward<t1>
        cout<<"animal constructor"<<endl;
        //this->tobj=t;
        cout<<"here"<<endl;
    }
    animal(test &&t):tobj{std::move(t)}{
        cout<<"animal r-value constructor"<<endl;
        //this->tobj=t;
        cout<<"here"<<endl;
    }
    ~animal(){
        cout<<"animal destructor tobj.name-"<<tobj.name<<endl;
    }
};

test func(){
    test tobj{"klo"};
    return tobj;
}

// template<typename T>
// void E(T&& t){
//     cout<<t.name<<endl;
// }
// template<typename T>
// void E(const T& t){
//     cout<<t.name<<endl;
// }

void E(const test& t){
    cout<<"lvalue t.name-"<<t.name<<endl;
}

void E(test&& t){
    cout<<"rvalue t.name-"<<t.name<<endl;
}

template<typename T>
void F(T&& t){
    //E(std::forward<T>(t));
    //E(t);
    E(std::move(t));
}

void some2(test t){
    cout<<t.name<<endl;
}
void some(test t){
    //cout<<t.name<<endl;
    some2(std::move(t));
    cout<<"--here2-"<<t.name<<endl;
}

int main(){
    // animal ani(func());//std::move(tobj)
    // //cout<<tobj.name<<endl;
    // test tobj("tobj");
    // animal ani2(tobj);

    test tobj("tobj");
    //F(tobj);

    //cout<<tobj.name<<endl;
    //F(func());
    some(tobj);
    cout<<"--here"<<tobj.name<<endl;
    return 0;
}
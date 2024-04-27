#include <iostream>
#include <memory>
using namespace std;

void somefunc(unique_ptr<int>p){
    cout<<*p<<endl;
}

void show(shared_ptr<int>p){
    cout<<*p<<endl;
    cout<<p.use_count()<<endl;
}

int main(){
    // int *a=nullptr;
    // cout<<*a<<endl;
    // int *ptr=new int(4);
    // unique_ptr<int>p(ptr);
    // somefunc(std::move(p));
    // cout<<*p<<endl;
    //delete ptr;

    // shared_ptr<int>sp1{new int(3)};
    // cout<<*sp1<<endl;
    // show(sp1);
    // cout<<sp1.use_count()<<" "<<*sp1<<endl;

    char c='a';
    int *p1=(int*)&c;
    cout<<*p1<<endl;
    
    int a=34;
    char *p2=(char*)&a;
    cout<<*p2<<endl;

    return 0;
}
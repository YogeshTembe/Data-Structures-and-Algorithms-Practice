#include<iostream>
#include<memory>
using namespace std;

void somefunc1(int *p){
    cout<<"in somefunc1 *p-"<<*p<<endl;
}

void somefunc2(shared_ptr<int> &ptr){
    cout<<"in somefunc2 *ptr-"<<*ptr<<endl;
}

void somefunc3(shared_ptr<int>ptr){
    cout<<"in somefunc3 *ptr-"<<*ptr<<" use_count-"<<ptr.use_count()<<endl;

}

class test{
    public:
    int a;
    test(int a){
        cout<<"called test constructor"<<endl;
        this->a=a;
    }
    ~test(){
        cout<<"called test destructor"<<endl;
    }
};

int main(){
    shared_ptr<int>sptr{new int(34)};
    somefunc1(sptr.get());
    cout<<*sptr<<" "<<sptr<<endl;
    somefunc2(sptr);
    cout<<*sptr<<" "<<sptr<<endl;
    somefunc3(sptr);
    cout<<*sptr<<" use_count-"<<sptr.use_count()<<endl;

    test *t1=new test(56);
    cout<<"t1-"<<t1<<" &t1-"<<&t1<<endl;
    shared_ptr<test>sptr2{t1};
    shared_ptr<test>sptr3=sptr2;

    cout<<sptr2<<" "<<sptr3<<endl;
    cout<<&sptr2<<" "<<&sptr3<<endl;

    cout<<sptr2->a<<" "<<sptr3->a<<endl;
    cout<<sptr2.use_count()<<" "<<sptr3.use_count()<<endl;
    sptr3.reset();
    cout<<sptr2<<" "<<sptr3<<endl;
    cout<<sptr2.use_count()<<" "<<sptr3.use_count()<<endl;
    return 0;
}
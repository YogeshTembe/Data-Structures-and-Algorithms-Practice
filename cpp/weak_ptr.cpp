#include<iostream>
#include<memory>
using namespace std;


class employee;

class project{
    public:
        weak_ptr<employee>emp;
        ~project(){
            cout<<"project destructor"<<endl;
        }
};

class employee{
    public:
        weak_ptr<project>proj;
        ~employee(){
            cout<<"employee destructor"<<endl;
        }
};

int main(){
    // shared_ptr<int>sptr{new int(45)};
    // cout<<sptr.use_count()<<endl;
    // shared_ptr<int>sptr3=sptr;
    // weak_ptr<int>wkptr=sptr;
    // cout<<sptr.use_count()<<endl;
    // //std::cout<<"helo"<<endl;
    // shared_ptr<int>sptr2=wkptr.lock();
    // cout<<sptr.use_count()<<" "<<wkptr.expired()<<" "<<sptr2.use_count()<<endl;

    // shared_ptr<employee>emp1{new employee()};
    // shared_ptr<project>pro1{new project()};
    // emp1->proj=pro1;
    // pro1->emp=emp1;

    shared_ptr<int>sptr{new int(45)};
    weak_ptr<int>wptr=sptr;
    cout<<*sptr<<" "<<sptr.use_count()<<endl;
    sptr.reset();
    cout<<sptr.use_count()<<endl;
    shared_ptr<int>sptr2=wptr.lock();
    cout<<wptr.expired()<<endl;
    cout<<*sptr2<<" "<<sptr2.use_count()<<endl;
    return 0;
}
#include<iostream>
using namespace std;

class animal{
    public:
    animal(){
        cout<<"animal constructor"<<endl;
    }
    virtual void show(){
        cout<<"show animal"<<endl;
    }
    virtual ~animal(){
        cout<<"animal destructor"<<endl;
    }
};

class dog:public animal{
    public:
    string name;
    dog(string n):name(n){
        cout<<"dog constructor"<<endl;
    }
    void show() override final{
        cout<<"show dog-"<<this->name<<endl;
    }
    void some(){
        cout<<"some"<<endl;
    }
    ~dog(){
        cout<<"dog destructor"<<endl;
    }
};

// class furrydog: public dog{
    
// };

int main(){
    // animal *ani=new dog("par");
    // ani->show();
    // delete ani;

    // dog john("doja");
    // animal *ani2=&john; 
    // ani2->show();

    //usecase = multiple inheritance
    //animal *ani2=new animal();
    // if(typeid(*ani2)==typeid(dog)){
    //     cout<<"here"<<endl;
    //     dog *john2=dynamic_cast<dog*>(ani2);
    //     john2->show();
    // }

    // dog *kim=new dog("kim");
    // animal *ani3=kim;
    // ani3->show();

    animal ani4;
    dog romi("romi");
    ani4=romi;
    ani4.show();
    // animal ani;
    // cout<<sizeof(ani)<<endl;
    return 0;
}
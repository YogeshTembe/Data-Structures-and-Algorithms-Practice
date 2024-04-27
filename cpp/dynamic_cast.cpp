#include<iostream>
using namespace std;

class animal{
    public:
    string name;
    animal(string name){
        cout<<"animal constructor called"<<endl;
        this->name=name;
    }

    virtual void sound(){
        cout<<"animal sound"<<endl;
    }
};

class dog:public animal{
    public:
    dog(string name):animal(name){
        cout<<"dog constructor called"<<endl;
    }
    void sound() override{
        cout<<"bark"<<endl;
    }
    void getstick(){
        cout<<"getstick"<<endl;
    }
};

class cat:public animal{
    public:
    cat(string name):animal(name){
        cout<<"cat constructor called"<<endl;
    }
    void sound() override{
        cout<<"meow"<<endl;
    }
};

void makeanimalSound(animal *ani){
    dog *dptr=dynamic_cast<dog*>(ani);
    if(dptr!=nullptr){
        dptr->getstick();
    }
    //OR
    // if(typeid(*ani)==typeid(dog)){
    //     cout<<"its a dog"<<endl;
    //     dog *dptr=static_cast<dog*>(ani); 
    //     dptr->getstick();
    //     //ani->getstick(); //compilation error, even if ani pointer contains dog obj still we get error because this info is not available at compiletime
    // }
    ani->sound();
}

int main(){
    // animal ani("ani");
    // //cout<<sizeof(animal);
    // ani.sound();
    // dog john("john");
    // john.sound();
    // cat kit("kit");
    // kit.sound();

    animal *ani=new dog("john");
    animal *ani2=new cat("kit");
    makeanimalSound(ani);
    makeanimalSound(ani2);

    //convert a cat to dog
    //dog *dptr=new cat("kio");
    return 0;
}
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include <algorithm> 
using namespace std;

class test{
    public:
    string name;
    int pos;
    test(string n):name(n){this->pos=56;}

    bool operator<(const test& t) const{
        return this->name.length()<t.name.length();
    }

    bool operator==(const test& t) const{
        return this->name.length()==t.name.length();
    }
};

struct comp{
    bool operator()(const test& t1,const test& t2) const{
        return t1.name.length()<t2.name.length();
    }
};

struct testhash{
    size_t operator()(const test& t) const{
        auto s1=hash<string>{}(t.name);
        auto s2=hash<int>{}(t.pos);
        return s1^s2;
    }
};

struct testwitht1{
    vector<test>tvec;
    void operator()(const test& t){
        if(t.name=="t1"){tvec.push_back(t);}
    }
};

int main(){
    // hash<string>h;
    // const type_info &t=typeid(h("hello"));
    // size_t a=89;
    // const type_info &t1=typeid(a);
    // cout<<t.name()<<" "<<t1.name()<<endl;
    
    // vector<test>vec;
    test t1{"t1"};
    test t2{"t22"};
    test t3{"t1"};
    // vec.push_back(t1);
    // vec.push_back(t2);
    // for(auto a:vec){
    //     cout<<a.name<<endl;
    // }

    //set<test,comp>ustest;
    // unordered_set<test,testhash>ustest;
    // ustest.insert(t1);
    // ustest.insert(t2);
    // for(auto a:ustest){
    //     cout<<a.name<<endl;
    // }
    
    //
    vector<test>vec;
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    // auto count=std::count_if(vec.begin(),vec.end(),[](const auto &e){
    //     return e.name=="t1";
    // });
    // cout<<count<<endl;

    auto foundobj=for_each(vec.begin(),vec.end(),testwitht1());
    cout<<foundobj.tvec.size()<<endl;
    return 0;
}
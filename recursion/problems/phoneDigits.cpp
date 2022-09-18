#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

set<string> res;
std::map<string,vector<string>> phone;

void print(vector<string>s){
    cout<<"vector-";
    for(auto a:s){
        cout<<a<<" ";
    }
    cout<<endl;
}

void possibleWords2(int a[], int N, int index){
    //cout<<index<<endl;
    if(index>N-1){
        //print(res);
        return;
    }
    if(index==0){
        auto chars=phone.find(to_string(a[index]));
        for(auto c:chars->second){
            res.insert(c);
        }
    }else{
        //cout<<"a-"<<to_string(a[index])<<endl;
        auto chars=phone.find(to_string(a[index]));
        //print(chars->second);
        set<string>temp;
        for(auto c:chars->second){
            for(auto itr = res.begin(); itr != res.end(); itr++){
                temp.insert(*itr+c);
            }
        }
        //print(temp);
        res=temp;
    }
    possibleWords2(a,N,index+1);
}


vector<string> possibleWords(int a[], int N)
{
    //Your code here
    phone.insert({"2",{"a","b","c"}});
    phone.insert({"3",{"d","e","f"}});
    phone.insert({"4",{"g","h","i"}});
    phone.insert({"5",{"j","k","l"}});
    phone.insert({"6",{"m","n","o"}});
    phone.insert({"7",{"p","q","r","s"}});
    phone.insert({"8",{"t","u","v"}});
    phone.insert({"9",{"w","x","y","z"}});
    possibleWords2(a,N,0);
    std::vector<string> output(res.begin(), res.end()); 
    return output;
}

int main(){
    int a[]={2,3,4,7};
    auto r=possibleWords(a,4);
    print(r);
    cout<<r.size();
    return 0;
}
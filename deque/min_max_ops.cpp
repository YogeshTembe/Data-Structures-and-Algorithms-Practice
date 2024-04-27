#include<iostream>
#include<deque>
using namespace std;

class myds{
    private:
    deque<int>dq;
    public:
    myds(){
        dq={};
    }
    void insertMax(int x){
        dq.push_back(x);
    }
    void insertMin(int x){
        dq.push_front(x);
    }
    int getMin(){
        return dq.front();
    }
    int getMax(){
        return dq.back();
    }
    int extractMin(){
        int ans=dq.front();
        dq.pop_front();
        return ans;
    }
    int extractMax(){
        int ans=dq.back();
        dq.pop_back();
        return ans;
    }
};

int main(){
    myds* ds=new myds();
    ds->insertMin(5);
    ds->insertMax(10);
    ds->insertMin(3);
    ds->insertMax(15);
    ds->insertMin(2);
    cout<<ds->getMin()<<endl;
    cout<<ds->getMax()<<endl;
    ds->insertMin(1);
    cout<<ds->getMin()<<endl;
    ds->insertMax(20);
    cout<<ds->getMax()<<endl;
    return 0;
}
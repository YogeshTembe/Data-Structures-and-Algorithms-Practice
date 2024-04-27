#include<iostream>
#include<vector>
using namespace std;

//Open Addressing using double hashing
class myHashTable{
    int* arr;
    int size;
    public:
    myHashTable(int s){
        arr=new int[s];
        this->size=2*s;
        for(int i=0;i<this->size;i++){
            arr[i]=-1;
        }
    }
    bool isFull(){
        for(int i=0;i<this->size;i++){
            if(arr[i]==-1 || arr[i]==-2){
                return false;
            }
        }
        return true;
    }
    bool insert(int key){
        //double hasing
        if(this->isFull()){
            return false;
        }
        int probe=key%this->size;
        int offset=(this->size-1)-(key)%(this->size-1);
        cout<<probe<<endl;
        while(arr[probe]!=-1 && arr[probe]!=-2){
            probe=(probe+offset)%(this->size);
        }
        arr[probe]=key;
        return true;
    }

    int search(int key){
        int probe=key%this->size;
        int offset=(this->size-1)-(key)%(this->size-1);
        //cout<<"p-"<<probe<<endl;
        if(arr[probe]==key){
            return probe;
        }
        vector<int>visited(this->size,0);
        //cout<<"visited[probe]-"<<visited[probe]<<endl;
        while((arr[probe]!=-1) && visited[probe]!=1){
            probe=(probe+offset)%(this->size);
            //cout<<"p-"<<probe<<endl;
            if(arr[probe]==key){
                return probe;
            }
            visited[probe]=1;
        }
        return -1;
    }

    void erase(int key){
        int idx=this->search(key);
        if(idx!=-1){
            arr[idx]=-2;
        }
    }

    void print(){
        for(int i=0;i<this->size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    auto mh=new myHashTable(7);
    mh->insert(2);
    mh->insert(5);
    mh->insert(49);
    mh->insert(56);
    mh->insert(63);
    mh->insert(28);
    mh->print();
    cout<<mh->search(5)<<endl;
    cout<<mh->search(28)<<endl;
    mh->erase(63);
    mh->insert(15);
    mh->insert(42);
    cout<<mh->search(42)<<endl;
    mh->print();
    return 0;
}
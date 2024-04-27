#include<iostream>
#include<vector>
#include<list>
using namespace std;

struct myHashTable{
    int bucket;
    list<int>*table;
    myHashTable(int bucketsize){
        bucket=bucketsize;
        table=new list<int>[bucket];//pointer to array of lists of size "bucket"
    }
    void insert(int key){
        int i=key%bucket;//hash fn
        table[i].push_back(key);
    }
    void remove(int key){
        int i=key%bucket;//hash fn
        table[i].remove(key);
    }
    bool search(int key){
        int i=key%bucket;//hash fn
        for(auto a:table[i]){
            if(a==key){return true;}
        }
        return false;
    }
    void printHashTable(){
        for(int i=0;i<bucket;i++){
            auto lst=table[i];
            for(auto a:lst){
                cout<<a<<" ";
            }
            if(lst.size()!=0){
                cout<<endl;
            }
        }
    }
};

int main(){
    myHashTable* ht=new myHashTable(7);
    ht->insert(49);
    ht->insert(50);
    ht->insert(21);
    ht->insert(34);
    ht->printHashTable();
    ht->remove(21);
    ht->printHashTable();
    cout<<ht->search(50);
    return 0;
}
#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int d):data(d),next(NULL),prev(NULL){}
};



class LRUCache
{
    private:
        Node *head;
        Node *tail;
        unordered_map<int,Node*>mp; 
        unordered_map<int,int>data;
        int capacity;
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->capacity=cap;
        this->head=NULL;
        this->tail=NULL;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {   
        //cout<<"get-"<<key<<endl;
        // your code here
        if(mp.find(key)!=mp.end()){
            Node *movetofrontnode=mp[key];
            if(movetofrontnode==this->head){
                return data[key];
            }
            Node *nextnode=movetofrontnode->next;
            Node *prevnode=movetofrontnode->prev;
            if(this->tail==movetofrontnode){
                this->tail=this->tail->prev;
            }
            prevnode->next=nextnode;
            if(nextnode){
                nextnode->prev=prevnode;
            }
            movetofrontnode->prev=NULL;
            movetofrontnode->next=this->head;
            this->head->prev=movetofrontnode;
            this->head=movetofrontnode;
            return data[key];
        }else{
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here  
        Node *newnode=new Node(key);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(this->capacity>data.size()){
            if(head==NULL && tail==NULL){
                this->head=newnode;
                this->tail=newnode;
            }else{
                this->head->prev=newnode;
                newnode->next=this->head;
                newnode->prev=NULL;
                this->head=newnode;
            }
        }else{
            if(mp.find(key)!=mp.end()){
                //cout<<"set key found"<<endl;
                data[key]=value;
                Node *movetofrontnode=mp[key];
                if(movetofrontnode==this->head){
                    return;
                }
                Node *nextnode=movetofrontnode->next;
                Node *prevnode=movetofrontnode->prev;
                if(this->tail==movetofrontnode){
                    this->tail=this->tail->prev;
                }
                prevnode->next=nextnode;
                if(nextnode){
                    nextnode->prev=prevnode;
                }
                movetofrontnode->prev=NULL;
                movetofrontnode->next=this->head;
                this->head->prev=movetofrontnode;
                this->head=movetofrontnode;
                // cout<<"--"<<this->head->data<<" "<<this->tail->data<<endl;
                // cout<<this->head->next->data<<endl;
                // this->printList();
                return;
            }
            Node *prevnode=this->tail->prev;
            Node *tobedeleted=this->tail;
            //cout<<"tobedeleted->data-"<<tobedeleted->data<<endl;
            //cout<<"tail->prev"<<tail->prev<<endl;
            mp.erase(tobedeleted->data);
            data.erase(tobedeleted->data);
            //cout<<"prevnode->data-"<<prevnode<<endl;
            prevnode->next=NULL;
            this->tail=this->tail->prev;
            // delete(tobedeleted);
            //cout<<"this->head-"<<this->head<<endl;
            this->head->prev=newnode;
            newnode->next=this->head;
            newnode->prev=NULL;
            this->head=newnode;
        }
        mp.insert({key,newnode});
        data.insert({key,value});
    }

    void printList(){
        Node *curr=this->head;
        while(curr){
            cout<<curr->data<<" ----";
            curr=curr->next;
        }
        cout<<endl;
    }
};

int main(){
    /*
        2
        8
        SET 1 2 SET 2 3 SET 1 5 GET 2 SET 3 4 SET 2 4 SET 4 5 GET 2
    */
    LRUCache *lc=new LRUCache(2);
    lc->SET(1,2);
    lc->SET(2,3);
    //lc->printList();
    lc->SET(1,5);
    //lc->printList();
    cout<<lc->GET(2)<<endl;
    lc->SET(3,4);
    lc->SET(2,4);
    lc->SET(4,5);
    //lc->printList();
    cout<<lc->GET(2)<<endl;

    // lc->SET(10,1);
    // lc->SET(20,2);
    // cout<<lc->GET(30)<<endl;
    // lc->SET(30,3);
    // lc->SET(40,4);
    // lc->printList();
    // cout<<lc->GET(30)<<endl;
    // lc->printList();
    // lc->SET(50,5);
    // lc->printList();
    // cout<<lc->GET(50)<<endl;
    // lc->printList();
    // lc->SET(60,6);
    // lc->printList();
    // lc->SET(60,7);
    // lc->printList();
    // cout<<lc->GET(30)<<endl;
    // lc->printList();
    // cout<<lc->GET(30)<<endl;
    // cout<<lc->GET(30)<<endl;
    return 0;
}
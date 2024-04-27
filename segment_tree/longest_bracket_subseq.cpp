#include<iostream>
#include<cmath>
using namespace std;

struct Node {
    int pairs;
    int open;   
    int closed;

    Node() { pairs = open = closed = 0; }
};

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

Node merge(Node first,Node second){
    Node res=Node{};
    int minpairs = min(first.open,second.closed);
    res.pairs = first.pairs + second.pairs + minpairs;
    res.open = first.open + second.open - minpairs;
    res.closed = first.closed + second.closed - minpairs;
    return res;
}

void constructSTUtil(string str, int ss, int se, Node* st, int si) {
    if(ss==se){
        //base case
        st[si].pairs=0;
        if(str[ss]=='('){ st[si].open = 1; }
        else{ st[si].closed = 1; }
        return;
    }
    int mid=getMid(ss,se);
    constructSTUtil(str,ss,mid,st,2*si+1);
    constructSTUtil(str,mid+1,se,st,2*si+2);
    st[si]=merge(st[2*si+1],st[2*si+2]);
    //cout<<" p-"<<st[si].pairs<<" "<<ss<<" "<<se<<endl;
}

Node* constructST(string str, int n) {
    int x = (int)(ceil(log2(n)));

    int max_size = 2 * (int)pow(2, x) - 1;
    Node* st = new Node[max_size];

    constructSTUtil(str, 0, n - 1, st, 0);
    return st;
}

Node getNumberOfPairsInRange(Node *st,int qs,int qe,int ss,int se,int si){
    if(qs>se || ss>qe){
        Node nullnode;
        return nullnode;
    }
    if(qs<=ss && qe>=se){
        //cout<<st[si].pairs<<" "<<ss<<" "<<se<<endl;
        return st[si];
    }
    
    int mid=getMid(ss,se);
    Node first=getNumberOfPairsInRange(st,qs,qe,ss,mid,2*si+1);
    Node second=getNumberOfPairsInRange(st,qs,qe,mid+1,se,2*si+2);
    //cout<<first.pairs<<" "<<second.pairs<<endl;
    Node res=merge(first,second);
    //cout<<qs<<" "<<qe<<" "<<mid<<" "<<si<<" "<<res.pairs<<endl;
    return res;
}

int getLongestSequence(Node* st, string str, int qs, int qe, int n) 
{
    // add code here
    int pairs=getNumberOfPairsInRange(st,qs,qe,0,n-1,0).pairs;
    return 2*pairs;
}

int main(){
    string str="())(())(())(";
    int n=12;
    Node *st=constructST(str,n);
    cout<<getLongestSequence(st,str,3,6,n)<<endl;
    cout<<getLongestSequence(st,str,0,11,n)<<endl;
    return 0;
}
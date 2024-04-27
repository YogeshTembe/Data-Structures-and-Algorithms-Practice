#include<iostream>
using namespace std;

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
    MinHeapNode(char d,int f):data(d),freq(f){}
};

string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    // Code here
    string res;
    MinHeapNode* temp=root;
    for(int i=0;i<binaryString.length();i++){
        if(temp->data!='$'){
            res+=temp->data;
            temp=root;
            continue;
        }
        if(binaryString[i]=='0'){
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return res;
}

int main(){
    //01110100011111000101101011101000111
    /*
       $(13)
                      /        \
                    /            \
                  /                \
               $(5)                  \
             /      \                  \
            /        \                   \
         $(3)         \                  $(8)
        /    \         \                /    \
     $(2)     \         \            $(4)     \
    /   \      \         \          /   \      \
f(1)    o(1)    r(1)    g(2)    k(2)    s(2)    e(4)
    */
    MinHeapNode* root=new MinHeapNode('$',13);
    MinHeapNode* node1=new MinHeapNode('$',5);
    MinHeapNode* node2=new MinHeapNode('$',8);
    MinHeapNode* node3=new MinHeapNode('$',8);
    MinHeapNode* node4=new MinHeapNode('$',8);
    MinHeapNode* node5=new MinHeapNode('$',8);
    MinHeapNode* node6=new MinHeapNode('$',8);


    return 0;
}
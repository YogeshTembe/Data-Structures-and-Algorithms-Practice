#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
{ 
    //Your code here
    vector<int>temp;
    int i=0;
    int j=0;
    while(i<A.size() && j<B.size()){
        if(A[i]<B[j]){
            temp.push_back(A[i]);
            i++;
        }
        else if(A[i]>B[j]){
            temp.push_back(B[j]);
            j++;
        }
        else if(A[i]==B[j]){
            temp.push_back(A[i]);
            temp.push_back(B[j]);
            i++;j++;
        }
    }

    while(i<A.size()){
        temp.push_back(A[i]);
        i++;
    }

    while(j<B.size()){
        temp.push_back(B[j]);
        j++;
    }

    int k=0;
    int s=0;
    vector<int>temp2;
    while(k<C.size() && s<temp.size()){
        if(C[k]<temp[s]){
            temp2.push_back(C[k]);
            k++;
        }
        else if(temp[s]<C[k]){
            temp2.push_back(temp[s]);
            s++;
        }
        else if(temp[s]==C[k]){
            temp2.push_back(temp[s]);
            temp2.push_back(C[k]);
            k++;s++;
        }
    }

    while(k<C.size()){
        temp2.push_back(C[k]);
        k++;
    }

    while(s<temp.size()){
        temp2.push_back(temp[s]);
        s++;
    }
    return temp2;
} 

int main(){
    vector<int>A = {1,2,3,4}; 
    vector<int>B = {1,2,3,4,5}; 
    vector<int>C = {1,2,3,4,5,6};
    auto res=mergeThree(A,B,C);
    for(auto r:res){
        cout<<r<<" ";
    }
    cout<<endl;
    return 0;
}
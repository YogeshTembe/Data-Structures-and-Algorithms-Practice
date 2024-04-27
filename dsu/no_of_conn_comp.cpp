#include<iostream>
#include<vector>
using namespace std;

int find(int x,int arr[]){
    if(x==arr[x]){ return x; }
    arr[x]=find(arr[x],arr);
    return arr[x];
}

//Function to merge two nodes a and b.
void unionNodes( int a, int b, int arr[], int rank1[], int n) 
{
    //code here
    int a_par=find(a,arr);
    int b_par=find(b,arr);
    if(a_par==b_par){return;}
    if(rank1[a_par]<rank1[b_par]){ arr[a_par]=b_par; }
    else if(rank1[b_par]<rank1[a_par]){ arr[b_par]=a_par; }
    else{ arr[a_par]=b_par; rank1[b_par]++; }
}

//Function to determine number of connected components.
int findNumberOfConnectedComponents( int n, int arr[], int rank1[]) 
{
    //code here
    int nc=n;
    for(int i=0;i<n;i++){
        if(arr[i]==i){nc--;}
    }
    return nc;
}

int main(){
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
    Item(int v,int w):value(v),weight(w){}
};

bool comp(Item a,Item b){
    return (a.value/a.weight)>(b.value/b.weight);
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr,arr+n,comp);
    float curr=0;
    int res=0;
    int i=0;
    while(curr<W && i<n){
        cout<<arr[i].weight<<" "<<curr<<" "<<res<<endl;
        if((curr+arr[i].weight)<W){
            curr+=arr[i].weight;
            res+=arr[i].value;
        }else{
            int frac=(W-curr);
            curr+=(W-curr);
            res+=(arr[i].value/arr[i].weight)*frac;
            break;
        }
        i++;
    }
    return res;
}

int main(){
    // Item i1=Item(60,10);
    // Item i2=Item(100,20);
    // Item i3=Item(120,30);
    // Item arr[]{i1,i2,i3};
    // cout<<fractionalKnapsack(50,arr,3);
    Item i1=Item(60,10);
    Item i2=Item(100,20);
    Item arr[]{i1,i2};
    cout<<fractionalKnapsack(50,arr,2);
    return 0;
}
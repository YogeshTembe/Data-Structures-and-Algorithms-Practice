#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void previousGreaterElement(vector<int>arr){
    stack<int>s;
    s.push(0);
    cout<<-1<<" ";
    for(int i=1;i<arr.size();i++){
        while(s.empty()==false && arr[s.top()]<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            cout<<-1<<" ";
        }else{
            cout<<arr[s.top()]<<" ";
        }
        s.push(i);
    }
    cout<<endl;
}

int main(){
    vector<int>arr{15,10,18,12,4,6,2,8};
    previousGreaterElement(arr);
    cout<<sizeof(int)<<endl;
    return 0;
}
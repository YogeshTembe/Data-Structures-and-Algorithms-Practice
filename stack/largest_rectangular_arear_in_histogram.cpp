#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//Better solution
//Requires 3 traversals
//Time complexity=O(n) space complexity=O(n)
int largestRecArea(vector<int>hist){
    //find previous smaller
    stack<int>pstack;
    vector<int>ps;
    pstack.push(0);
    ps.push_back(-1);
    for(int i=1;i<hist.size();i++){
        while(!pstack.empty() && hist[pstack.top()]>=hist[i]){
            pstack.pop();
        }
        if(pstack.empty()){ps.push_back(-1);}
        else{ps.push_back(pstack.top());}
        pstack.push(i);
    }
    for(auto p:ps){cout<<p<<" ";}
    cout<<endl;
    //find next smaller
    stack<int>nstack;
    vector<int>ns;
    nstack.push(hist.size());
    ns.push_back(hist.size());
    for(int i=hist.size()-2;i>=0;i--){
        while(!nstack.empty() && hist[nstack.top()]>=hist[i]){
            nstack.pop();
        }
        if(nstack.empty()){ns.push_back(hist.size());}
        else{ns.push_back(nstack.top());}
        nstack.push(i);
    }
    reverse(ns.begin(),ns.end());
    for(auto n:ns){cout<<n<<" ";}
    cout<<endl;
    //Actual impl to find largest Rec area
    int res=INT_MIN;
    for(int i=0;i<hist.size();i++){
        int curr=hist[i];
        curr+=(i-ps[i]-1)*hist[i];
        curr+=(ns[i]-i-1)*hist[i];
        res=max(res,curr);
    }
    return res;
}

//Efficient method
//Requires One traversal
//Time complexity=O(n), space complexity=O(n)
int largestRacArea2(vector<int>hist){
    stack<int>s;
    int res=INT_MIN;
    for(int i=0;i<hist.size();i++){
        while(!s.empty() && hist[s.top()]>=hist[i]){
            int topele=s.top();
            s.pop();
            int curr=s.empty()?i:(i-s.top()-1);
            res=max(res,hist[topele]*curr);
        }
        s.push(i);
    }
    //process remaining elements
    while(!s.empty()){
        int topele=s.top();
        s.pop();
        int curr=s.empty()?hist.size():(hist.size()-s.top()-1);
        res=max(res,hist[topele]*curr);
    }
    return res;
}

int main(){
    vector<int>hist{6,2,5,4,1,5,6};
    cout<<largestRacArea2(hist);
    return 0;
}
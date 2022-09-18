#include<iostream>
using namespace std;

int betBalance(string result)
{
    // code here
    int nextBet=1;
    int currsum=4;
    int i=0;
    while(currsum>0 && i<result.length()){
        if(currsum<nextBet){return -1;}
        if(result[i]=='W'){
            currsum+=nextBet;
            nextBet=1;
        }else{
            currsum-=nextBet;
            nextBet*=2;
        }
        i++;
    }
    if(currsum<0){return -1;}
    return currsum;
}

int main(){
    cout<<betBalance("WLWLLWLLWWLWWW")<<endl;
    cout<<betBalance("WLWLLLWWLW");
    return 0;
}
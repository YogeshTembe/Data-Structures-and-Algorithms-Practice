#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

static int currItr=1;

bool isLucky2(int n){
    currItr++;
    cout<<currItr<<" "<<n<<endl;
    if(n<currItr){
        return true;
    }
    if(n%currItr==0){
        return false;
    }
    return isLucky2((n-int(n/currItr))); 
}

// bool isLucky(int n) {
//     // code here

    
// }

int main(){
    cout<<isLucky2(19);
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//my solution
vector<int> removeElement(vector<int> n,int ele, int startIndex){
    bool found=false;
    if(startIndex > n.size()-1){return vector<int>{-100};}
    for(int i=startIndex+1;i<n.size();i++){
        if(!n.at(i)){break;}
        if(n.at(i)==ele){
            n[i]=-1;
            found=true;
            break;
        }
    }
    vector<int> a={-100};
    if(!found){
        return a;
    }
    
    return n;
}
int findOneOddOccuringNumber1(vector<int> n){
    vector<int> a;
    for(int i=0;i<n.size();i++){
        if(n.at(i)!=-1){
            int ele=n.at(i);
            n=removeElement(n,ele,i);
            //cout<<n.size()<<endl;
            //cout<<"here2-"<<i<<" "<<n.at(i)<<endl;
            if(n==vector<int>{-100}){return ele;}
        }
    }
    return -1;
}

//naive solution
//time complexity - O(n^2)
int findOneOddOccuringNumber2(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        int count=0;
        for(int j=0;j<arr.size();j++){
            if(arr[j]==arr[i]){
                count++;
            }
        }
        if(count%2!=0){
            return arr[i];
        }
    }
    return -1;
}

//efficient solution using xor 
//xor of 2 same numbers is 0 
//x^x=0, x^0=x, x^y=y^x
//so based to these properties all the numbers occuring even number of times cancel each other and xor becomes zero because x^x=0
//and only odd occuring number remains as result because x^0=x
int findOneOddOccuringNumber3(vector<int> arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=res^arr[i];
    }
    return res;
}

int main(){
    //vector<int> n={4,4,4,4,3,8,8};
    vector<int> n={8,7,7,3,8,8,8,9,9,5,5};
    cout<<findOneOddOccuringNumber1(n)<<endl;
    cout<<findOneOddOccuringNumber2(n)<<endl;
    cout<<findOneOddOccuringNumber3(n)<<endl;
    return 0;
}
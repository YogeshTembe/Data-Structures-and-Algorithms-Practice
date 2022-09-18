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
void findTwoOddOccuringNumber1(vector<int> n){
    vector<int>res;
    for(int i=0;i<n.size();i++){
        if(n.at(i)!=-1){
            int ele=n.at(i);
            auto r=removeElement(n,ele,i);
            if(r==vector<int>{-100}){res.push_back(ele);continue;}
            n=r;
            //cout<<n.size()<<endl;
            //cout<<"here2-"<<i<<" "<<n.at(i)<<endl;
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res.at(i)<<" ";
    }
}
/////////////////////////////////////////////////////////////////////////

//efficient solution - (using xor)
//consider a and b are the elements that are odd occuring
//Do the xor of all numbers since here we have 2 odd occuring elements we get a^b as result 
//now we want to find a and b ... we have a xor b
//property of xor -> if two bits of numbers are different then xor gives 1 as output ... and if two bits are same then xor gives 0 as output
//so we just find the rightmost bit in a^b and based on that bit we seperate array into two groups
//now we know for sure that a and b are in two different groups
//now just find xor of all elements of group1 store in result1 and xor of all elements of xor2 store in result2
//we get a and b as result1 and result2
//example-> 
int findOneOddOccuringNumber3(vector<int> arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=res^arr[i];
    }
    return res;
}
void findTwoOddOccuringNumber2(vector<int> arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=res^arr[i];
    }
    int setBit=res & ~(res-1); //to find the rightmost setbit in res
    cout<<res<<" "<<setBit<<endl;
    vector<int> group1;
    vector<int> group2;
    for(int i=0;i<arr.size();i++){
        if(setBit & arr[i]){
            group1.push_back(arr[i]);
        }else{
            group2.push_back(arr[i]);
        }
    }
    cout<<findOneOddOccuringNumber3(group1)<<" ";
    cout<<findOneOddOccuringNumber3(group2)<<endl;
}

int main(){
    vector<int> n={3,4,3,4,5,4,4,6,7,7};
    //vector<int> n={8,7,7,3,8,8,8,9,9,5,5,4};
    findTwoOddOccuringNumber1(n);
    cout<<endl;
    findTwoOddOccuringNumber2(n);
    //cout<<findOneOddOccuringNumber2(n)<<endl;
    //cout<<findOneOddOccuringNumber3(n)<<endl;
    return 0;
}
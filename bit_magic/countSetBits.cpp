#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//naive solution
//check the last bit is set and if yes then inc the result 
//shift the number right with every iteration
//time complexity=tita(total no. of bits in compiler)
int countSetBits1(int n){
    int setBits=0;
    while(n>0){
        //cout<<n<<" ";
        if(n & 1 ==1){
            setBits++;
        }
        n=n>>1;
    }
    return setBits;
}

//efficient solution 
//standard algorithm - brian kerningam algorithm
//In every iteration we turn off the left most bit in n and we go on turning off each bit till we reach right most bit
//when we AND n with n-1 we turn off the rightmost set bit
//time complexity - tita(no of set bits)
int countSetBits2(int n){
    int setBits=0;
    while(n>0){
        n=(n & (n-1));
        setBits++;
    }
    return setBits;
}

//more efficient solution
//lookup table method
//It requires pre-processing i.e. we need to create a table with 256 entries and 
//then we check 32bits in the chunks of 8 bits
//the table contains the count of set bits in each number from 0 to 255 (2^8 -1)
//time complexity - tita(1)
vector<int> table;

void intializeTable(){
    table.push_back(0);
    for(int i=1;i<256;i++){
        table[i]=(i&1)+table[i/2];
    }
}

int countSetBits3(int n){
    intializeTable();
    int setBits=table[n&0xff];
    n=n>>8;
    setBits=setBits+table[n&0xff];
    n=n>>8;
    setBits=setBits+table[n&0xff];
    n=n>>8;
    setBits=setBits+table[n&0xff];
    n=n>>8;
    return setBits;
}

int main(){
    cout<<countSetBits1(10)<<endl;
    cout<<countSetBits2(10)<<endl;
    cout<<countSetBits3(10)<<endl;
    return 0;
}
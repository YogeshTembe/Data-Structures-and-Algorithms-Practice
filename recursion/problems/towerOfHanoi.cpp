#include<iostream>
using namespace std;

long long toh(int N, int from, int to, int aux) {
    if(N==1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        return 1;
    }
    long long moves=toh(N-1,from,aux,to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    moves=moves+toh(N-1,aux,to,from);
    return moves+1;
}

int main(){
    cout<<toh(3,1,3,2);
    return 0;
}
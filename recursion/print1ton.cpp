#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    print(n-1);
}

void print2(int n){
    if(n==0){
        return;
    }
    print2(n-1);
    cout<<n<<" ";
}

int fact(int n){
    if(n==0 || n==1){return 1;}
    return n*fact(n-1);
}

void fact2(int n, int* res){
    if(n==0 || n==1){
        return;
    }
    *res=(*res)*n;
    fact2(n-1,res);
}

vector<int> res;

int fibo(int n){
    if (n <= 1){
        return n;
    }
    //cout<<n<<" ";
    return fibo(n-1) + fibo(n-2);
}

//sum of first n natural numbers
int sumOf(int n,int sum){
    if(n==0){
        return sum;
    }
    sum=sum+n;
    return sumOf(n-1,sum);
}

//palindrome
bool isPalindrome(string s){
    if(s.length()==0 || s.length()==1){
        return true;
    }
    if(s[0]==s[s.length()-1]){
        return isPalindrome(s.substr(1,s.length()-2));
    }
    return false;
}

//sum of digits in a number
int sumOfDigits(int n, int sum){
    if(n<=0){
        return sum;
    }
    sum=sum+n%10;
    return sumOfDigits(n/10,sum);
}

int main(){
    //print(3);
    //print2(3);

    // int r=1;
    // fact2(5,&r);
    // cout<<r;
    
    //cout<<fibo(4);

    //cout<<sumOf(5,0);

    // string s="abba";
    // int mid=s.length()/2;
    // cout<<isPalindrome(s);

    cout<<sumOfDigits(10,0);
}
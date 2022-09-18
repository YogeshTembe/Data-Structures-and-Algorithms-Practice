#include <iostream>
#include <math.h>

using namespace std;

bool isPalindrome(int num, int n){
    cout<<"n"<<n<<endl;
    int temp=num;
    int arr[n];
    int newnum=0;
    for(int i=0;i<n;i++){
        arr[i]=num%10;
        cout<<num%10<<endl;
        num=num/10;
    }
    cout<<"array-"<<endl;
    for(int i=n-1;i>=0;i--){
        cout<<"arr-"<<arr[i]<<" "<<arr[i]*pow(10,i)<<" "<<newnum<<endl;
        newnum=newnum+arr[i]*pow(10,i);
    }
    cout<<"newnum-"<<newnum<<" num-"<<temp;
    if(newnum==temp){
        return true;
    }
    return false;
}

int countDigits(int num){
    int count=0;
    while(num>0){
        num=num/10;
        count++;
    }
    return count;
}

int main()
{
    cout<<"Hello World";
    int a=282;
    bool result=isPalindrome(a,countDigits(a));
    cout<<"result-"<<result;
    return 0;
}

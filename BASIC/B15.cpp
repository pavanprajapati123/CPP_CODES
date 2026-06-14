#include<iostream>
using namespace std;
int main(){
    int n;
    int temp,rev=0,rem;
    cout<<"enter a number :";
    cin>>n;
    temp=n;
    while(n!=0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    cout<<"reversed number is "<<rev<<endl;

 if(rev==temp)
    cout<<"temp is palindrome"<<temp<<endl;
else

    cout<<"temp is not palindrome"<<temp<<endl;
    return 0;
}
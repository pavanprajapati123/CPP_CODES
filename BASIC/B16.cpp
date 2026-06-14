#include<iostream>
using namespace std;
int main(){
    int n,sum=0,rem,lastDigit;
    cout<<"enter a number :";
    cin>>n;
    int temp=n;
    lastDigit = n % 10;
    while(n>0){
        rem=n%10;
    sum=sum+rem;
     n=n/10;  
    }
    cout<<"sum is "<<sum<<endl;  
    cout << "Last digit is: " << lastDigit << endl;
}

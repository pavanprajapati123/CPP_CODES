#include<iostream>
using namespace std;
int main(){
    int n=167;
    int rev=0;
    for(int i=0;i<=n;i++){
        int digit=n%10;
        rev=rev*10+digit;
        n=n/10;
    }
    
       cout<<"Reversed number is:"<<rev<<endl;
       return 0;
    
}
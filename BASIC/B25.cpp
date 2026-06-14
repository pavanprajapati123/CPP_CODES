#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter the number";
    cin>>n;
    int count=0;
    if(n>=1){
    for (int i = 2; i < n; i++) {
        if(n%i==0){
        cout<<"prime number"<<endl;
        }
        else{
            cout<<"not prime number";
        }
            return 0;
        
    }
    }
}


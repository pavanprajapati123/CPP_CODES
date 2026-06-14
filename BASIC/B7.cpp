#include<iostream>
using namespace std;
int main(){
    int i=2;
    int n,count=0;
    cout<<"Enter a number:";
    cin>>n;
    for(i=2;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }  
        if (count==1)
        {
            cout<<"not prime";
        }else {
        cout<<"  prime";
    }
}

    
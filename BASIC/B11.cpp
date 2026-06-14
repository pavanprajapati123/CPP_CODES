#include<iostream>
using namespace std;
int main(){
    int n; int pro=1; 

    cout<<"enter a number";
    cin>>n;
    while (n>0)
    {
        pro=pro*n%10;
        n=n/10;
        
    }
    cout<<"pro is" <<pro<<endl;

}
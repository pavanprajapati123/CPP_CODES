#include<iostream>
using namespace std;
int main(){
     int n=267;
     int coun=0;
     for(;0<n;){
         n/=10;
             coun++;
         }
     
     cout<<"Number of divisors are:"<<coun<<endl;
     
     return 0;
}
    
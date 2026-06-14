#include<iostream>
using namespace std;
int main(){
    int a[5]={3,4,2,8,5};
    int b[5]={4,9,8,5,3};
    int c[5];
    int k=0;
    for(int i=0;i<5; i++){
        for(int j=0;j<5;j++){
            if(a[i]==b[j]){
                c[k]=a[i];
                k++;
                break;
            }
        }
    }
    cout<<"common values:";
    for(int i=0;i<k;i++){
        cout<<c[i]<<endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100],num;
    cout<<"enter size of arry";
    cin>>n;
    cout<<"enter number to search";
    cin>>num;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i] == num){
            cout<<"number found at index "<<i<<endl;
            break;
        }
    }
    return 0;
}

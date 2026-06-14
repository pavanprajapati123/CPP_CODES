#include <iostream>
using namespace std;

int main() {
    int arr[5]={5,4,9,4,5};
    int sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        sum+=arr[i];
        
    }
    int mid=n/2;
    cout<<arr[mid]<<endl;
    
    return 0;
}

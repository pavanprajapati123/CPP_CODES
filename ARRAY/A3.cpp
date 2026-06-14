// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5]={10,20,30,40,50};
//     int start=0;
//     int n=5;
//     int end=n-1;
//     while (start<end)
//     {
//        swap(arr[start],arr[end]);
//         start ++;
//         end--;
//     }
//     cout<<"reverse number is ";
//     for (int i=0;i<5;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
    
//     }
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[6]={10,20,30,40,50,60};
//     int n=6;
//     for(int i=0;i<n;i+2){
//         swap(arr[i],arr[i+1]);
//     }
//     cout<<"swapped array is ";
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main(){
    int arr1[ ]={10,20,30,40,50,60};
    int arr2[ ]={20,5,10,50,6,40}; 
    int arr3[6];
    int n=6;
    swap(arr1,arr2);
    for(int i=0;i<n;i++){
        arr3[i]=arr1[i];
    }
    cout<<" array is ";
    for(int i=0;i<n;i++){
        cout<<arr3[i]<<" ";
    }
}
    
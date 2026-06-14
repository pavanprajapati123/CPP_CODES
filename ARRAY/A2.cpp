#include<iostream>
using namespace std;
int main(){
    int arr[5]={10,20,30,40,50};
    int key, i;
    cout<<"enter key to search:";
    cin>>key;
    for ( i = 0; i < 5; i++)
    { 
        if(arr[i]==key){
        cout<< key << " found at index " << i << endl;
        }
        return 0;
    }
cout<<"not found"<<endl;
return 0;
}
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
//     cout<<"reverse number is"<<arr;
//     for (int i=0;i<5;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
    
//     }

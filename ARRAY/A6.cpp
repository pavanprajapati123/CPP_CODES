#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={2,4,6,8,10,12,14,16,18,20};
    int size=sizeof(arr)/sizeof(int);
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    int result=binarysearch(arr,size,key);
    if(result!=-1)
    {
        cout<<"Element found at index: "<<result<<endl;
    }
    else
    {
        cout<<"Element not found"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int binarysearch(int arr[],int n,int key)
{
    int start=0;
    int end= n-1;
    
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return true;
        }
        else if (arr[mid]<key)
        {
            start=mid+1;
        }
        else if (arr[mid]>key)
        {
            end=mid-1;
        }
    }
    return false;
}
int main(){
   int arr[]={1,2,3,4,5,6,7};
   int n=sizeof(arr)/sizeof(arr[0]);
   int key=4;
   cout<<binarysearch(arr,n,key);

}
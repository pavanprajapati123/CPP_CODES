#include<iostream>
using namespace std;
void linearserch(int row[], int column[], int key){
    int arr_size = sizeof(row)/sizeof(row[0]);
    for(int i=0; i<arr_size; i++){
        if(row[i]==key){
            cout<<"Element found at row index: "<<i<<endl;
            return;
        }
        if(column[i]==key){
            cout<<"Element found at column index: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}
int main(){
    int row[]={1,2,3,4,5};
    int column[]={6,7,8,9,10};
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    linearserch(row,column,key);
    return 0;
}
#include<iostream>
using namespace std;
void sort012(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    for(int i=0;i<n; i++){
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
    int main(){
        int arr[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
        int n = sizeof(arr) / sizeof(arr[0]);
        sort012(arr, n);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return 0;
    }

    
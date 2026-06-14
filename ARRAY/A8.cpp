
#include<iostream>
using namespace std;

int main(){
    int arr[]={0,1,0,1,0,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        while (arr[left] == 0 && left < right){

            left++;
        }
        while (arr[right] == 1 && left < right){
            right--;
        }
        if (left <= right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    cout << "array shorted is : ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}




// #include<iostream>
// using namespace std;

// int main(){
//     int arr[]={0,1,0,1,0,1,0,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int left = 0;
//     int right = n-1;

//     while (left < right)
//     {
//         while (arr[left] == 1 && left < right)
//             left++;

//         while (arr[right] == 0 && left < right)
//             right--;

//         if (left < right)
//         {
//             swap(arr[left], arr[right]);
//             left++;
//             right--;
//         }
//     }

//     cout <<"result: ";
//     for(int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }


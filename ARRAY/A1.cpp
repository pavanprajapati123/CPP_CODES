// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5] = {10, 20, 30, 40, 50};
//     int key; 
//     cout << "Enter the element to search: ";
//     cin >> key;
//     for(int i=0; i<5; i++){
//         if(arr[i] == key){
//            cout<<"element a number = "<<key<<endl;
//         cout<<"element in a index = "<<i<<endl;
//         }
//     }
//     return 0;

// }

// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5] = {10, 20, 30, 40, 50};
//     int sum = 0;
//     for(int i = 0; i < 5; i++){
//         sum = sum + arr[i];
//     }

//     cout << "Sum of array elements: " << sum << endl;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int arr[5] = {10, 20, 30, 40, 50};
//     int sum = 0;
//     for(int x : arr){
//         sum = sum + x;
//     }

//     cout << "Sum of array elements: " << sum << endl;
// }

//product of arry !!
#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    int product=1;
    for(int i=1; i<5;i++){
        product=product*arr[i];
    }
    cout<<"product of "<<product<<endl;
}
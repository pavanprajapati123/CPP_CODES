// #include<iostream>
// using namespace std;
// void pattern(int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             char ch='A'+j;
//             cout<<ch;
//         }
//         cout<<endl;
//     }
// } 
// int main(){
//     int n;
//     cin>>n;
//     cout<<"Pattern is: "<<endl;
//     pattern(n);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// void pattern(int n) {
//     for (int i = 0; i < n; i++) {

//         char start = 'A' + (n - 1 - i);
//         char last = 'A' + (n - 1);

//         for (char ch = 'C'; ch >= 'A'; ch--) {
//             cout << ch;
//             if (ch > last) {
//                 cout << " ";  
//             }
//         }

//         cout << endl;  
// }
// }

// int main() {
//     int n = 5; 
//     cout << "Pattern is: " << endl;   
//     cin >> n;
//     pattern(n);
//     return 0;
// }


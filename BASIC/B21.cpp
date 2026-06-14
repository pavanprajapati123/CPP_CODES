// #include<iostream>
// using namespace std;
// void AtoD(){
//     int A=65; // ASCII value of 'A'
//     int n=26;
//     for(int i=0;i<n;i++)
//     {
//         cout<<char(A+i)<<" ";
//     }
// }
// int main(){
//     AtoD();
//     return 0;
// }
//C

//BC
//ABC
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
#include<iostream>
using namespace std;

void pattern(int n){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= 3; j++){
            char ch = 'A' + j;
            cout << ch;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    cout << "Pattern is: " << endl;
    pattern(n);
    return 0;
}

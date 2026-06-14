#include<iostream>
using namespace std;
int  diagonal_sum(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int primarySum = 0;
    int secondarySum = 0;

    for(int i = 0; i < 3; i++) {
        primarySum += arr[i][i];
        secondarySum += arr[i][2 - i];
    }

    cout << "Primary Diagonal Sum = " << primarySum << endl;
    cout << "Secondary Diagonal Sum = " << secondarySum << endl;
    cout << "Total Diagonal Sum = " << primarySum + secondarySum << endl;
}
int main(){
    diagonal_sum();
    return 0;
}
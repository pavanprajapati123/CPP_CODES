#include<iostream>
using namespace std;

void diagonal_sum() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int secondarySum = 0;

    for(int i = 0; i < 3; i++) {
        secondarySum += arr[i][3 - 1 - i];
    }

    cout << "Secondary Diagonal Sum = " << secondarySum << endl;
}

int main() {
    diagonal_sum();
    return 0;
}
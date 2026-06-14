#include <iostream>
#include <utility>
using namespace std;

int total_sum(int arr[][3], int rows, int cols, int &row) 
{   
    int maxSum = 0;  
    for(int i = 0; i < rows; i++) {
        int sum = 0;

        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }

        if(sum > maxSum) {
            maxSum = sum;
			row=i;
        }
	}
	
    return maxSum;
}

int main() {
    int arr[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
	int roww=-1;

    int ans = total_sum(arr, 4, 3, roww);

    cout << "Max Row Sum = " << ans<< endl;
    cout << "Row Index   = " << roww<< endl;

    return 0;
}
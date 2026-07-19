//sum of the maximum and minimum elements
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sumOfMaxMin(int arr[], int n)
    {
        sort(arr, arr + n);

        return arr[0] + arr[n - 1];
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Sum of Maximum and Minimum = "
         << obj.sumOfMaxMin(arr, n);

    return 0;
}
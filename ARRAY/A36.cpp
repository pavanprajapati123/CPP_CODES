//Indexes of Subarray Sum..
#include <iostream>
using namespace std;

int subarraySum(int* arr, int n, int target, int* res)
{
    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; right++)
    {
        sum += arr[right];

        while (sum > target && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
        {
            res[0] = left + 1;   // 1-based indexing
            res[1] = right + 1;

            return 1;
        }
    }

    return 0;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    int res[2];

    if (subarraySum(arr, n, target, res))
    {
        cout << "Subarray Found from Index "
             << res[0] << " to "
             << res[1] << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}
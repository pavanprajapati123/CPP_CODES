#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                return arr[i];
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = findDuplicate(arr, n);

    cout << "Duplicate Element = "
         << ans << endl;

    return 0;
}
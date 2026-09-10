//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> waveFormArray(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 1; i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }

        return arr;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();

    vector<int> result = obj.waveFormArray(arr, n);

    cout << "Wave Form Array: ";

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}
//Check If Any Three Sides Can Form a Triangle
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool possibleToMakeTriangle(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        for(int i = 0; i < n - 2; i++)
        {
            if((long long)arr[i] + arr[i + 1] > arr[i + 2])
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    if(obj.possibleToMakeTriangle(arr))
        cout << "Triangle Possible";
    else
        cout << "Triangle Not Possible";

    return 0;
}
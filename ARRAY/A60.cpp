//3336 find the number of secquences with equal gcd
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool check(int x, vector<int>& arr)
    {
        long long cur = x;

        for(int num : arr)
        {
            cur = 2LL * cur - num;

            if(cur <= 0)
                return false;
        }

        return true;
    }

    int find(vector<int>& arr)
    {
        int x = 1;

        while(true)
        {
            if(check(x, arr))
                return x;

            x++;
        }
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
        cin >> arr[i];

    Solution obj;

    cout << "Minimum Initial Value = "
         << obj.find(arr);

    return 0;
}
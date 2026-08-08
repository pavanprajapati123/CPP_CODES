//3301. Allocate Minimum Number of Pages
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:

    bool isPossible(vector<int>& arr, int n, int m, long long limit)
    {
        int students = 1;
        long long pages = 0;

        for(int i = 0; i < n; i++)
        {
            if(pages + arr[i] <= limit)
            {
                pages += arr[i];
            }
            else
            {
                students++;
                pages = arr[i];

                if(students > m)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int n, int m)
    {
        if(m > n)
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        long long ans = -1;

        while(low <= high)
        {
            long long mid = low + (high - low) / 2;

            if(isPossible(arr, n, m, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter pages of books: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> m;

    Solution obj;

    cout << "Minimum Maximum Pages = "
         << obj.findPages(arr, n, m);

    return 0;
}
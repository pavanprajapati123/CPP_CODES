//Fruit Into Baskets Using Sliding Window
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxFruits(vector<int> &arr, int n)
    {
        unordered_map<int, int> mp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < n; right++)
        {
            mp[arr[right]]++;

            while(mp.size() > 2)
            {
                mp[arr[left]]--;

                if(mp[arr[left]] == 0)
                    mp.erase(arr[left]);

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
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

    cout << "Maximum Fruits = "
         << obj.findMaxFruits(arr, n);

    return 0;
}
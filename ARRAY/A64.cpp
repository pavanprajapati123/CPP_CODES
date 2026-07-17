// sorted gcd  pair queries
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int gcd(int a, int b)
    {
        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
    {
        vector<int> gcdPairs;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                gcdPairs.push_back(gcd(nums[i], nums[j]));
            }
        }

        sort(gcdPairs.begin(), gcdPairs.end());

        vector<int> ans;

        for(long long q : queries)
        {
            ans.push_back(gcdPairs[q]);
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;

    cout << "Enter number of queries: ";
    cin >> q;

    vector<long long> queries(q);

    cout << "Enter query indices: ";
    for(int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }

    Solution obj;

    vector<int> ans = obj.gcdValues(nums, queries);

    cout << "Answers: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
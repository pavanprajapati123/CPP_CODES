// Mountain Subarray Queries
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> processQueries(vector<int> &arr,
                                vector<vector<int>> &queries)
    {
        int n = arr.size();

        vector<int> inc(n, 1), dec(n, 1);

        // Length of Non-Decreasing sequence ending at i
        for(int i = 1; i < n; i++)
        {
            if(arr[i] >= arr[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        // Length of Non-Increasing sequence starting at i
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i] >= arr[i + 1])
                dec[i] = dec[i + 1] + 1;
        }

        vector<bool> ans;

        for(auto &q : queries)
        {
            int l = q[0];
            int r = q[1];

            bool ok = false;

            // Try every possible peak
            for(int peak = l; peak <= r; peak++)
            {
                bool left = (peak - inc[peak] + 1 <= l);
                bool right = (peak + dec[peak] - 1 >= r);

                if(left && right)
                {
                    ok = true;
                    break;
                }
            }

            ans.push_back(ok);
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
        cin >> arr[i];

    int q;

    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    cout << "Enter queries (l r):\n";

    for(int i = 0; i < q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;

    vector<bool> ans = obj.processQueries(arr, queries);

    cout << "Answers: ";

    for(bool x : ans)
    {
        if(x)
            cout << "true ";
        else
            cout << "false ";
    }

    return 0;
}
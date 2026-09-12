//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct State
    {
        long long score;
        vector<int> ids;

        State()
        {
            score = 0;
        }

        State(long long s, vector<int> v)
        {
            score = s;
            ids = v;
        }
    };

    // Return true if a is better than b
    bool better(const State& a, const State& b)
    {
        // First maximize score
        if (a.score != b.score)
            return a.score > b.score;

        // If score is same, lexicographically smaller
        // indices are preferred
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals)
    {
        int n = intervals.size();

        // Store:
        // {left, right, weight, originalIndex}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++)
        {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        // next[i] = first interval whose left > a[i][1]
        vector<int> next(n);

        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
        {
            starts[i] = a[i][0];
        }

        for (int i = 0; i < n; i++)
        {
            long long right = a[i][1];

            next[i] = upper_bound(
                starts.begin(),
                starts.end(),
                right
            ) - starts.begin();
        }

        /*
            dp[i][k] =
            best result using intervals from i to n-1
            when we can still choose at most k intervals.
        */

        vector<vector<State>> dp(
            n + 1,
            vector<State>(5)
        );

        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = 1; k <= 4; k++)
            {
                // Option 1: Skip current interval
                State skip = dp[i + 1][k];

                // Option 2: Take current interval
                int j = next[i];

                State take = dp[j][k - 1];

                take.score += a[i][2];

                // Add original index
                take.ids.push_back((int)a[i][3]);

                // Result must be sorted by original index
                sort(take.ids.begin(), take.ids.end());

                // Choose better option
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].ids;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> intervals = {
        {1, 3, 4},
        {2, 4, 3},
        {5, 7, 6},
        {6, 8, 5}
    };

    vector<int> result = obj.maximumWeight(intervals);

    cout << "Selected interval indices: ";

    for (int id : result)
    {
        cout << id << " ";
    }

    return 0;
}
// 1520  Maximum Substrings using Greedy
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Create valid interval for every character
        for (int c = 0; c < 26; c++)
        {
            if (first[c] == n)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int i = l; i <= r; i++)
            {
                int x = s[i] - 'a';

                // This character occurs before l,
                // so this interval cannot be valid.
                if (first[x] < l)
                {
                    valid = false;
                    break;
                }

                // Include all occurrences of this character
                r = max(r, last[x]);
            }

            if (valid)
            {
                intervals.push_back({r, l});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prevEnd = -1;

        // Greedily choose intervals with earliest ending
        for (auto& interval : intervals)
        {
            int r = interval.first;
            int l = interval.second;

            if (l > prevEnd)
            {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;

    string s = "adefaddaccc";

    vector<string> result = obj.maxNumOfSubstrings(s);

    cout << "Maximum substrings:\n";

    for (string str : result)
    {
        cout << str << "\n";
    }

    return 0;
}
//Get Marks According to Rank
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<int> getMarks(vector<int>& l,
                         vector<int>& r,
                         vector<int>& rank)
    {
        int n = l.size();

        vector<long long> pref(n);

        // Prefix sum of number of students
        // in each marks range
        for(int i = 0; i < n; i++)
        {
            long long cnt = r[i] - l[i] + 1;

            pref[i] = cnt;

            if(i > 0)
                pref[i] += pref[i - 1];
        }

        vector<int> ans;

        for(int x : rank)
        {
            int low = 0;
            int high = n - 1;

            // Find first range whose
            // cumulative count >= rank
            while(low < high)
            {
                int mid = low + (high - low) / 2;

                if(pref[mid] >= x)
                    high = mid;
                else
                    low = mid + 1;
            }

            int i = low;

            long long before = 0;

            if(i > 0)
                before = pref[i - 1];

            int marks =
                l[i] + (x - before - 1);

            ans.push_back(marks);
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of ranges: ";
    cin >> n;

    vector<int> l(n), r(n);

    cout << "Enter left limits:\n";

    for(int i = 0; i < n; i++)
        cin >> l[i];

    cout << "Enter right limits:\n";

    for(int i = 0; i < n; i++)
        cin >> r[i];

    int q;

    cout << "Enter number of ranks: ";
    cin >> q;

    vector<int> rank(q);

    cout << "Enter ranks:\n";

    for(int i = 0; i < q; i++)
        cin >> rank[i];

    Solution obj;

    vector<int> ans =
        obj.getMarks(l, r, rank);

    cout << "Marks: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
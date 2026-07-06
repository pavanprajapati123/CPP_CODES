//1288. Remove Covered Intervals
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        int ans = n;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;

                if(intervals[j][0] <= intervals[i][0] &&
                   intervals[i][1] <= intervals[j][1])
                {
                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution obj;

    cout << "Remaining Intervals = "
         << obj.removeCoveredIntervals(intervals);

    return 0;
}
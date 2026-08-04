//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;

    return r1 > r2;
}

class Solution
{
public:
    double maximumValue(vector<pair<int, int>> &items, int n, int w)
    {
        sort(items.begin(), items.end(), cmp);

        double ans = 0.0;

        for(auto &it : items)
        {
            int weight = it.first;
            int value = it.second;

            if(w >= weight)
            {
                ans += value;
                w -= weight;
            }
            else
            {
                ans += (double)value * w / weight;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    int n, w;

    cout << "Enter number of items: ";
    cin >> n;

    vector<pair<int, int>> items(n);

    cout << "Enter weight and value of each item:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> items[i].first >> items[i].second;
    }

    cout << "Enter knapsack capacity: ";
    cin >> w;

    Solution obj;

    cout << "Maximum Value = "
         << obj.maximumValue(items, n, w);

    return 0;
}
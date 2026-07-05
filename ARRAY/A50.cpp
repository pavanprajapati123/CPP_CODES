//39. Combination Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, vector<int>& nums, int target)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }

        for(int i = start; i < nums.size(); i++)
        {
            if(nums[i] > target)
                continue;

            path.push_back(nums[i]);

            dfs(i, nums, target - nums[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dfs(0, candidates, target);

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> candidates[i];

    int target;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    vector<vector<int>> ans = obj.combinationSum(candidates, target);

    cout << "Combinations:\n";

    for(auto &vec : ans)
    {
        cout << "[ ";

        for(int x : vec)
            cout << x << " ";

        cout << "]\n";
    }

    return 0;
}
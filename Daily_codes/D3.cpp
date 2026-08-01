//486. Predict the Winner
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(vector<int>& nums, int i, int j)
    {
        if(i == j)
        {
            return nums[i];
        }

        int takeLeft = nums[i] - solve(nums, i + 1, j);

        int takeRight = nums[j] - solve(nums, i, j - 1);

        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums)
    {
        return solve(nums, 0, nums.size() - 1) >= 0;
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

    Solution obj;

    if(obj.predictTheWinner(nums))
        cout << "Player 1 Wins";
    else
        cout << "Player 2 Wins";

    return 0;
}
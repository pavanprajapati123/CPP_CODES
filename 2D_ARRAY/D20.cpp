//877. Stone Game
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(vector<int>& piles, int i, int j)
    {
        if(i == j)
        {
            return piles[i];
        }

        int left = piles[i] - solve(piles, i + 1, j);

        int right = piles[j] - solve(piles, i, j - 1);

        return max(left, right);
    }

    bool stoneGame(vector<int>& piles)
    {
        return solve(piles, 0, piles.size() - 1) > 0;
    }
};

int main()
{
    int n;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);

    cout << "Enter pile values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }

    Solution obj;

    if(obj.stoneGame(piles))
        cout << "Alice Wins";
    else
        cout << "Bob Wins";

    return 0;
}
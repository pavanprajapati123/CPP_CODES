//1291 sequential digits
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> sequentialDigits(int low, int high)
    {
        string s = "123456789";

        vector<int> ans;

        for(int len = 2; len <= 9; len++)
        {
            for(int i = 0; i + len <= 9; i++)
            {
                int num = stoi(s.substr(i, len));

                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int low, high;

    cout << "Enter low and high: ";
    cin >> low >> high;

    Solution obj;

    vector<int> ans = obj.sequentialDigits(low, high);

    cout << "Sequential Digits: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
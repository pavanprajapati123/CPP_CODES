//max gap between two same characters in a string
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    int maxCharGap(string &s)
    {
        int n = s.size();
        int ans = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    ans = max(ans, j - i - 1);
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter String: ";
    cin >> s;

    Solution obj;

    cout << "Maximum Character Gap = "
         << obj.maxCharGap(s);

    return 0;
}
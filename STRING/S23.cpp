//substring with more 1's than 0's
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int countSubstring(string &s)
    {
        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            if(s[i - 1] == '1')
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1] - 1;
        }

        int ans = 0;

        for(int i = 0; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(prefix[j] > prefix[i])
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{
    string s;

    cout << "Enter Binary String: ";
    cin >> s;

    Solution obj;

    cout << "Count = "
         << obj.countSubstring(s);

    return 0;
}
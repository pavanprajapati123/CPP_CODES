//2904 Shortest Beautiful Substring
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();

        int left = 0;
        int count = 0;

        string ans = "";

        for(int right = 0; right < n; right++)
        {
            if(s[right] == '1')
                count++;

            // More than k ones
            while(count > k)
            {
                if(s[left] == '1')
                    count--;

                left++;
            }

            // Remove unnecessary leading zeroes
            while(count == k && s[left] == '0')
            {
                left++;
            }

            // Current window is beautiful
            if(count == k)
            {
                string curr =
                    s.substr(left, right - left + 1);

                if(ans == "" ||
                   curr.size() < ans.size() ||
                   (curr.size() == ans.size() &&
                    curr < ans))
                {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};

int main()
{
    string s;
    int k;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Shortest Beautiful Substring = "
         << obj.shortestBeautifulSubstring(s, k);

    return 0;
}
//Longest Substring with At Most K Distinct Characters
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLengthofLongestSubstring(string s, int k)
    {
        int n = s.length();

        int freq[26] = {0};

        int left = 0;
        int distinct = 0;
        int ans = 0;

        for(int right = 0; right < n; right++)
        {
            // New character found
            if(freq[s[right] - 'a'] == 0)
            {
                distinct++;
            }

            freq[s[right] - 'a']++;

            // More than k distinct characters
            while(distinct > k)
            {
                freq[s[left] - 'a']--;

                if(freq[s[left] - 'a'] == 0)
                {
                    distinct--;
                }

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main()
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    cout << "Longest Substring Length: "
         << obj.getLengthofLongestSubstring(s, k);

    return 0;
}
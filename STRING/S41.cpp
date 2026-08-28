//3734 Lexicographically Smallest Palindromic Permutation Greater Than Target
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);

        // Count frequency of characters
        for(char c : s)
            cnt[c - 'a']++;

        // Find odd frequency character
        int odd = 0;
        char mid = 0;

        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] % 2)
            {
                odd++;
                mid = char('a' + i);
            }
        }

        // Palindrome is impossible
        if(odd > 1)
            return "";

        // Characters available for left half
        vector<int> leftCnt(26, 0);

        for(int i = 0; i < 26; i++)
            leftCnt[i] = cnt[i] / 2;

        // Try target's first half
        bool possible = true;

        for(int i = 0; i < half; i++)
        {
            int x = target[i] - 'a';

            leftCnt[x]--;

            if(leftCnt[x] < 0)
                possible = false;
        }

        // If target's first half can be used
        if(possible)
        {
            string left = target.substr(0, half);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if(n % 2)
                candidate += mid;

            candidate += right;

            if(candidate > target)
                return candidate;
        }

        // Backtrack from right side
        for(int i = half - 1; i >= 0; i--)
        {
            int x = target[i] - 'a';

            // Return target[i] to available characters
            leftCnt[x]++;

            for(int c = x + 1; c < 26; c++)
            {
                if(leftCnt[c] == 0)
                    continue;

                // Use the smallest character
                // greater than target[i]
                leftCnt[c]--;

                string left = target.substr(0, i);

                left += char('a' + c);

                // Fill remaining characters
                // in lexicographically smallest order
                for(int j = 0; j < 26; j++)
                {
                    left += string(
                        leftCnt[j],
                        char('a' + j)
                    );
                }

                string answer = left;

                // Add middle character
                if(n % 2)
                    answer += mid;

                // Add reverse half
                string rev = left;
                reverse(rev.begin(), rev.end());

                answer += rev;

                if(answer > target)
                    return answer;

                // Undo choice
                leftCnt[c]++;
            }
        }

        return "";
    }
};

int main()
{
    string s, target;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    string ans =
        obj.lexPalindromicPermutation(s, target);

    if(ans == "")
        cout << "No valid palindrome";
    else
        cout << "Answer = " << ans;

    return 0;
}
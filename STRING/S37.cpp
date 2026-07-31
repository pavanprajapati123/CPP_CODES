//3016 minimum number of pushes to type a word on a keyboard with 8 keys per row
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);

        for(char c : word)
        {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0)
            {
                break;
            }

            ans += freq[i] * ((i / 8) + 1);
        }

        return ans;
    }
};

int main()
{
    string word;

    cout << "Enter the word: ";
    cin >> word;

    Solution obj;

    cout << "Minimum Pushes = " << obj.minimumPushes(word);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> findPrefixes(vector<string> &arr)
    {
        vector<string> ans;

        for(string word : arr)
        {
            string prefix = "";

            for(char ch : word)
            {
                prefix += ch;

                int cnt = 0;

                for(string s : arr)
                {
                    if(s.substr(0, prefix.size()) == prefix)
                        cnt++;
                }

                if(cnt == 1)
                {
                    ans.push_back(prefix);
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> arr(n);

    cout << "Enter strings:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    vector<string> ans = obj.findPrefixes(arr);

    cout << "Unique Prefixes:\n";

    for(string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}
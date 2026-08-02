// Similarity and Union of two arrays
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m)
    {
        unordered_set<int> s1, uni;

        for(int x : arr1)
        {
            s1.insert(x);
            uni.insert(x);
        }

        int common = 0;

        for(int x : arr2)
        {
            if(s1.count(x))
            {
                common++;
            }

            uni.insert(x);
        }

        return {common, (int)uni.size()};
    }
};

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> arr1(n);

    cout << "Enter first array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> arr2(m);

    cout << "Enter second array elements: ";

    for(int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    Solution obj;

    pair<int, int> ans = obj.findSimilarity(arr1, arr2, n, m);

    cout << "Common Elements = " << ans.first << endl;
    cout << "Union Size = " << ans.second << endl;

    return 0;
}
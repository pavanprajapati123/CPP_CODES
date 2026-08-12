//Question: Two Sum / Book Pair
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string read(int n, vector<int> book, int target)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(book[i] + book[j] == target)
                {
                    return "YES";
                }
            }
        }

        return "NO";
    }
};

int main()
{
    int n, target;

    cout << "Enter number of books: ";
    cin >> n;

    vector<int> book(n);

    cout << "Enter book prices: ";

    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Enter target: ";
    cin >> target;

    Solution obj;

    cout << obj.read(n, book, target);

    return 0;
}
// sum of two arrays
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    vector<int> findArraySum(vector<int>& A, int n,
                             vector<int>& B, int m)
    {
        long long num1 = 0;
        long long num2 = 0;

        for(int x : A)
            num1 = num1 * 10 + x;

        for(int x : B)
            num2 = num2 * 10 + x;

        long long sum = num1 + num2;

        if(sum == 0)
            return {0};

        vector<int> ans;

        while(sum)
        {
            ans.push_back(sum % 10);
            sum /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter first array digits: ";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> B(m);

    cout << "Enter second array digits: ";
    for(int i = 0; i < m; i++)
        cin >> B[i];

    Solution obj;

    vector<int> ans = obj.findArraySum(A, n, B, m);

    cout << "Sum Array: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
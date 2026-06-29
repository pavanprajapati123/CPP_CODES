#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lowerArray(vector<int> &arr) {

        int n = arr.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++)
        {
            int count = 0;

            for(int j = i + 1; j < n; j++)
            {
                if(arr[j] < arr[i])
                    count++;
            }

            ans[i] = count;
        }

        return ans;
    }
};

int main() {

    int n;

    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;

    vector<int> ans = obj.lowerArray(arr);

    cout << "Answer: ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}
// C++ program to find the minimum distance between two numbers in an array
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDist(vector<int>& arr, int x, int y) {

        int ans = INT_MAX;
        bool foundX = false, foundY = false;

        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == x)
            {
                foundX = true;

                for(int j = 0; j < arr.size(); j++)
                {
                    if(arr[j] == y)
                    {
                        foundY = true;
                        ans = min(ans, abs(i - j));
                    }
                }
            }
        }

        if(!foundX || !foundY)
            return -1;

        return ans;
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int x, y;

    cout << "Enter x and y: ";
    cin >> x >> y;

    Solution obj;

    cout << "Minimum Distance = "
         << obj.minDist(arr, x, y);

    return 0;
}
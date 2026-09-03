//Flip Bits
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int flipBits(vector<int>& arr)
    {
        int totalOnes = 0;
        int currentGain = 0;
        int maxGain = 0;

        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 1)
            {
                totalOnes++;
                currentGain--;
            }
            else
            {
                currentGain++;
            }

            currentGain = max(0, currentGain);
            maxGain = max(maxGain, currentGain);
        }

        return totalOnes + maxGain;
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
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Maximum Ones after Flip: "
         << obj.flipBits(arr);

    return 0;
}
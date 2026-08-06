//// Question: Minimum Increment or Double Operations to Convert

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countMinOperations(vector<int>& arr)
    {
        int inc = 0;
        int dbl = 0;

        while(true)
        {
            bool allZero = true;

            // Count Increment Operations
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i] % 2 == 1)
                {
                    arr[i]--;
                    inc++;
                }

                if(arr[i] != 0)
                {
                    allZero = false;
                }
            }

            if(allZero)
            {
                break;
            }

            // Count Double Operations
            for(int i = 0; i < arr.size(); i++)
            {
                arr[i] /= 2;
            }

            dbl++;
        }

        return inc + dbl;
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

    cout << "Minimum Operations = "
         << obj.countMinOperations(arr);

    return 0;
}
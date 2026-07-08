//278 first Bad Version
#include <iostream>
using namespace std;

// Dummy API for VS Code Testing
bool isBadVersion(int version)
{
    int firstBad = 4;   // Change this value for testing
    return version >= firstBad;
}

class Solution {
public:

    int firstBadVersion(int n)
    {
        int low = 1;
        int high = n;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(isBadVersion(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{
    int n;

    cout << "Enter Total Versions: ";
    cin >> n;

    Solution obj;

    cout << "First Bad Version = "
         << obj.firstBadVersion(n);

    return 0;
}
//Second Largest element
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> getSecondOrderElements(int n, vector<int> a)
    {
        int largest = INT_MIN;
        int smallest = INT_MAX;

        // Find Largest and Smallest
        for(int x : a)
        {
            if(x > largest)
                largest = x;

            if(x < smallest)
                smallest = x;
        }

        int secondLargest = INT_MIN;
        int secondSmallest = INT_MAX;

        // Find Second Largest and Second Smallest
        for(int x : a)
        {
            if(x > secondLargest && x != largest)
                secondLargest = x;

            if(x < secondSmallest && x != smallest)
                secondSmallest = x;
        }

        return {secondLargest, secondSmallest};
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Solution obj;

    vector<int> ans = obj.getSecondOrderElements(n, a);

    cout << "Second Largest = " << ans[0] << endl;
    cout << "Second Smallest = " << ans[1] << endl;

    return 0;
}
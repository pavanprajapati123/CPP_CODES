#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int num : nums) {

            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        long long product1 =
            1LL * max1 * max2 * max3;

        long long product2 =
            1LL * min1 * min2 * max1;

        return max(product1, product2);
    }
};

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << "Maximum Product = "
         << obj.maximumProduct(nums)
         << endl;

    return 0;
}
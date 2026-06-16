
//414. Third Maximum Number
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {

            // Ignore duplicates
            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        return (third == LLONG_MIN) ? first : third;
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

    cout << "Third Maximum Element = "
         << obj.thirdMax(nums)
         << endl;

    return 0;
}
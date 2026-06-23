//349. Intersection of Two Arrays
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            mp[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++) {

            if (mp[nums2[i]] > 0) {
                ans.push_back(nums2[i]);

                // Duplicate avoid
                mp[nums2[i]] = 0;
            }
        }

        return ans;
    }
};

int main() {

    int n1;
    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> nums1(n1);

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }

    int n2;
    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> nums2(n2);

    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution obj;

    vector<int> result = obj.intersection(nums1, nums2);

    cout << "Intersection Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
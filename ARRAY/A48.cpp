// C++ program to find the majority element in an array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {

        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;

            for(int j = 0; j < n; j++)
            {
                if(arr[i] == arr[j])
                    cnt++;
            }

            if(cnt > n / 2)
                return arr[i];
        }

        return -1;
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

    Solution obj;

    cout << "Majority Element = "
         << obj.majorityElement(arr);

    return 0;
}
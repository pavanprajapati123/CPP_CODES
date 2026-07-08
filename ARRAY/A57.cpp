//intresection of two arrays
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void intersection(int input1[], int input2[], int size1, int size2)
    {
        unordered_map<int, int> mp;

        for(int i = 0; i < size2; i++)
        {
            mp[input2[i]]++;
        }

        for(int i = 0; i < size1; i++)
        {
            if(mp[input1[i]] > 0)
            {
                cout << input1[i] << " ";
                mp[input1[i]]--;
            }
        }
    }
};

int main()
{
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;

    int input1[size1];

    cout << "Enter first array elements: ";
    for(int i = 0; i < size1; i++)
        cin >> input1[i];

    cout << "Enter size of second array: ";
    cin >> size2;

    int input2[size2];

    cout << "Enter second array elements: ";
    for(int i = 0; i < size2; i++)
        cin >> input2[i];

    Solution obj;

    cout << "Intersection: ";
    obj.intersection(input1, input2, size1, size2);

    return 0;
}
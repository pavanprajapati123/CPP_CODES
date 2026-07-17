//Find Unique Element Using Brute Force
#include <iostream>
using namespace std;

class Solution
{
public:
    int findUnique(int arr[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            int cnt = 0;

            for(int j = 0; j < size; j++)
            {
                if(arr[i] == arr[j])
                    cnt++;
            }

            if(cnt == 1)
                return arr[i];
        }

        return -1;
    }
};

int main()
{
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];

    cout << "Enter array elements: ";

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    Solution obj;

    cout << "Unique Element = "
         << obj.findUnique(arr, size);

    return 0;
}
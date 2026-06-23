//   Merge 2 Sorted Arrays
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    set<int> st;

    for (int x : a)
        st.insert(x);

    for (int x : b)
        st.insert(x);

    vector<int> ans(st.begin(), st.end());

    return ans;
}

int main()
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> b(m);

    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<int> ans = sortedArray(a, b);

    cout << "Union of Arrays: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
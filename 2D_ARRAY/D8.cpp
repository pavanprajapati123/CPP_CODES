#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> a={1,2,3,4,5};
    cout<<a.size()<<" "<<a.capacity()<<endl;
    a.push_back(6);
    cout<<a.size()<<" "<<a.capacity()<<endl;
    return 0;
}

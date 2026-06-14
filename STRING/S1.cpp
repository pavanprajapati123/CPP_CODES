#include<string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& t) {
        int st=0;
        int e=t.size()-1;
        while(st<e)
        {
            swap(t[st++],t[e--]);
        }
    }
};
int main(){
    Solution sol;
    vector<char> t = {'h','e','l','l','o'};
    sol.reverseString(t);
    for(char c:t)
    {
        cout<<c<<" ";
    }
 }

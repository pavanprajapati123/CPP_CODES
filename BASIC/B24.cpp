//1. Print all odd numbers between 1 and 100
 //and print how many odd numbers were found.
#include <iostream>
using namespace std;
int main() {
    int n;
    int count=0;
    for (int  i = 1; i < 100; i++)
    {
        if (i % 2 !=0)
        {
             cout<<i<<endl;
            count++;
        }
        
    }
    cout<<"Total odd number  1 to 100 are: "<<count<<endl;
    return 0;
}
#include <iostream>
using namespace std;
// 1111
//  222
//   33
//    4
int main() {
    for (int  i = 1; i <= 4; i++)
    {
      for ( int j = 1; j < i; j++)
      {
        cout<<" ";
      }
      
      for (int  k = 4; k >= i; k--){
      
        cout<<i<<"";
      }
      cout<<endl;
    }
    
    return 0;
}

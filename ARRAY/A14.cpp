#include <iostream>
using namespace std;

int arr() {
    int arr[5] = {10, 0, 30, 40, 50};
     int totalsum=0;
      int missingnum=0;
      int sum1=0;
      for(int i=0;i<5;i++){
          totalsum=totalsum+arr[i];
      }
      sum1=(5*(5+1))/2;
        missingnum=sum1-totalsum;
        cout<<"The missing number is: "<<missingnum<<endl;

    return 0;
}
int main() {
    arr();
    return 0;
}
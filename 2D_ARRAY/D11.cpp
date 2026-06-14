#include <iostream>
#include<vector>
using namespace std;
class soluction{
    public:
    int searchInsert(vector<int > & arr,int target){
        int start=0;
        int end=arr.size()-1;
        int ans=arr.size();
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if (arr[mid]==target)
            {
                return mid;
            }
            else  if (arr[mid]<target)
            {
            
                start=mid+1;
            }
            else
            {
                 ans=mid;
                 end=mid-1;
            }
        }
        return ans;
    }  
  
};
     
      int main()
{
    soluction obj;
    vector<int> arr={1,3,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=5;
    cout<<obj.searchInsert(arr,target);
    
    return 0;
 }

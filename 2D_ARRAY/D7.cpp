#include<iostream>
using namespace std;
int diagonalsum(int mat[][3],int n){
    int sum=0;
    for (int  i = 0; i < n; i++)
    {
        sum+=mat[i][i];
        if (i!=n-i-1)
        {
            sum+=mat[i][n-i-1];
        }
        
    }
    return sum;
    
}
int main(){
    int matrix[][3]={ {1,2,3},
    {5,6,7},
    {9,10,11},
};
    int n=3;
    cout<<"diagonal sum is:"<<diagonalsum(matrix,n)<<endl;
    return 0;
}
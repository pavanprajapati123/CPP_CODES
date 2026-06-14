// #include<iostream>
// using namespace std;
// int main(){
//   int n;int pro=1;
//   cout<<"enter a number :";
//   cin>>n;
//   while(n>0){
//     pro=pro*n%10;
//     n=n/10;

//   }
  
//   cout<<"pro is "<<pro<<endl;  

// }
// #include<iostream>
// using namespace std;
// int main(){
//   int n=123; int r;
//   int sum=0;
//    while (n>0)
//    {
//      r=n%10;
//      sum=sum+r;
//      n=n/10;
//    }
//    cout<<"sum is "<<sum<<endl;
  
// }
// #include<iostream>
// using namespace std;
// int main(){
//   int num=2234; int count=0;
//   while(num>0){
  
//     pro=pro*n%10;
//     n=n/10;

//   cout<<"count a number is"<<count<<endl;
// }
// #include<iostream>
// using namespace std;
// int main(){
//   int n=123;
//   int pro=1,sum=0,r;
//   int ans,count=0;
//   while (n>0)
//   {
//     pro=pro*(n%10);
//     sum=sum+(n%10);
//      n=n/10;
//      count++;
//   }
//  ans= pro-sum;
//   cout<<"the number is "<<ans<<endl;
// }

#include<iostream>
using namespace std;
int main(){
  int n,i,count=0;
  cout<<"enter a number";
  cin>>n;
  for(int i=1; i<=n;i++){
    if(n%i==0){
      count++;
    }
  }
  if(count==2){
    cout<<"prime number "<<endl;
  }else
  cout<<"not prime"<<endl;
} 
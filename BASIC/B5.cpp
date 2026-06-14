
// question no. 1
#include<iostream>
using  namespace std;
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;
    if(n%2==0){
      cout<<"number is even";
    }else{
        cout<<"number is odd";  
    }
    return 0;
} 
//// question no. 2;
#include<iostream>
using namespace std;
int main(){
    int x=5;
    cout<<"x++:"<<x++<<endl<<"++x:"<<++x;
    
    return 0;
}
// question no. 4;
#include<iostream>
using namespace std;
int main(){
    int a=10;
    int b=a--;
    cout<<"a:"<<a<<endl<<"b:"<<b;

    return 0;
}
// question no. 5;
#include<iostream>
using namespace std;
int main(){
  int a,b;
  cout<<"enter two numbers:";
  cin>>a>>b;
  if(a>b){
    cout<<"a is the largest number";
  }else{
    cout<<"b is the largest number";
  }

    return 0;
}
// question no. 6;

#include<iostream>
using namespace std;
int main(){
    int num=7;
    cout<<"num++:"<<num++<<endl<<"++num:"<<++num;
    cout<<"the final value of num is:"<<num;

    return 0;
}
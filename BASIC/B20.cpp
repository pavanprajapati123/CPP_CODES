// #include<iostream>
// using namespace std;
//     int square(int n){
//         return n*n;
//     }
// int main(){
//     int n;
//     cout<<"enter number";
//     cin>>n;
//     int result=square(n);
//     cout<<"square:"<<result;
//     return 0;


// }
// #include<iostream>
// using namespace std;
//     void cheackevenodd(int n){
//         if(n%2==0){
//             cout<<"even number";
//         }
//         else{
//             cout<<"odd number";
//         }
//     }
// int main(){
//     int n;
//     cout<<"enter number";
//     cin>>n;
//     cheackevenodd(n);
//     return 0;
// }


//new code
// #include<iostream>
// using namespace std;
//    int square(int n)
// 	{
//         return n*n;
//    }
// int main()
// {
//     int n;
//     cout<<"enter number";
//     cin>>n;
//     int result=square(n);
//     cout<<"square:"<<result;
//     return 0;
// }

// #include<iostream>
// using namespace std;
//    void checkevenodd(int n)
//    {
//    	if(n%2==0)
//    	{
//    		cout<<"Even number"<<endl;
// 		}
// 		else
// 		{
// 			cout<<"Odd number"<<endl;
// 		}
// 	}
// 	int main()
// 	{
// 		int n;
// 		cout<<"Enter a number"<<endl;
// 		cin>>n;
// 		checkevenodd(n);
// 		return 0;
// 	}



#include<iostream>
using namespace std;
int fact(int n)
{
	int f=1;
	for(int i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
}
int main()
{
	int n;
	cout<<"Enter number";
	cin>>n;
	int factorial=fact(n);
	cout<<"factorial:"<<fact(n);
	return 0;
}




// #include<iostream>
// using namespace std;
// int maximum(int a,int b)
// {
// 	if(a>b)
// 	{
// 		return a;
// 	}
// 	else
// 	{
// 		return b;
// 	}
// }
// int main()
// {
// 	int x;
// 	cout<<"Enter a number";
// 	cin>>x;
	
// 	int y;
// 	cout<<"Enter another number";
// 	cin>>y;
	
// 	cout<<"Maximum:"<<maximum(x,y);
// 	return 0;
// }
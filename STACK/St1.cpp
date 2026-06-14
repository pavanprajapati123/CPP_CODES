#include <iostream>
using namespace std;
class stack{
 public:
    int *arr;
    int size;
    int top;
      stack(int s){
        size=s;
        top=-1;
        arr=new int[size];
    }
      void push(int data){
        if(top==size-1){
            cout<<" overflow"<<endl;
            return;
        }
        arr[++top]=data;
    
    }
       void pop(){
        if(top==-1){
            cout<<"underflow \n";
            return;
        }
        top--;
    }
    bool isEmpty(){
        return top==-1;
    }
     int peek(){
        if(top==-1){
            cout<<"stack is empty \n";
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
    int getsize(){
        return top+1;
    }
    ~stack(){
        delete[]arr;
    }
};
  int main() {
     stack st(3);
     st.push(22);
     st.push(23);
     st.push(24);
     cout<<st.peek()<<endl;
     st.pop();
     cout<<st.peek()<<endl;
     cout<<"size: "<<st.getsize()<<endl;
    return 0;
}

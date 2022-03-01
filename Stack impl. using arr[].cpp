#include<bits/stdc++.h>
using namespace std;

int n=100;

class stackk{
    int *arr;
    int top;
    public:
    stackk(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        top++;
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return ;
        }
        arr[top]=x;
    }
    void Top(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        cout<<arr[top]<<endl;
    }
    void pop(){
        if(top==-1){
            cout<<"No element in stack"<<endl;
            return ;
        }
        top--;
    }
    bool empty(){
        return top==-1;
    }
};
int main() {
    stackk st;
    st.push(1);
    st.push(2);
    st.Top();
    st.pop();
    st.Top();
    st.empty();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
return 0;
}
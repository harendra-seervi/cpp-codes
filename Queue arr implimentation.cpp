#include<bits/stdc++.h>
using namespace std;
int n=20;

// we don't create queue class name because it is ambeguis in #include<bits/stdc++.h> library
// in this library queue syntex is already present so that's why im named q insted of queue

class q{
    int *arr;
    int front;
    int back;
    public:
    q(){
        arr=new int [n];
        front=-1;
        back=-1;
    }
    void enq(int x){
        if(back==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1){
            front++;
        }
    }
    void deq(){
        if(front>back){
            cout<<"Stack overflow"<<endl;
            return;
        }
        front++;
    }
    void peek(){
        if(front==-1 || front>back){
            cout<<"No element "<<endl;
            return ;
        }
        cout<<arr[front]<<endl;
    }
    bool empty(){
        if(front>back || front==-1 ){
            return true;
        }
        return false;
    }

};
int main(){
    q a;
    a.enq(1);
    a.enq(2);
    a.enq(3);
    a.enq(4);
    a.enq(5);

    a.peek();
    a.deq();
    a.peek();
    a.deq();
    a.peek();
    a.deq();
    cout<<a.empty()<<endl;
    a.deq();
    a.peek();
    cout<<a.empty()<<endl;
    a.deq();
    a.peek();
    cout<<a.empty()<<endl;

return 0;
}
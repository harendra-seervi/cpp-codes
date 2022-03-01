#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    public:
    node*back;
    node*front;
    queue(){
        back=NULL;
        front=NULL;
    }
    void push(int val){
        node*n=new node(val);
        if(back==NULL && front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=back->next;
    }
    void pop(){
        if(front==NULL){
            cout<<"Nothing is avalible in queue"<<endl;
            return ;
        }
        node*todel=front;
        front=front->next;
        delete todel;
    }
    int peek(){
        if(front==NULL){
            cout<<"queue is empty"<<endl;
            return -1 ;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL || back==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.empty()<<endl;
    cout<<endl;
    cout<<q.peek()<<endl;
    q.push(4);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<endl;
    cout<<q.empty()<<endl;
return 0;
}
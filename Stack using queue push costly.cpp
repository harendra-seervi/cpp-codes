#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int>q1;
    queue<int>q2;
    public:
    void push(int val){
        q2.push(val);
        while(q1.empty()!=true){
            q2.push(q1.front());
            q1.pop();
        }
        while(q2.empty()!=true){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        q1.pop();

    }
    int peek(){
        return q1.front();
    }
    bool empty(){
        if(q1.empty()==true && q2.empty()==true) return true;
        return false;
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}
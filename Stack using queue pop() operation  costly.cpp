#include<iostream>
#include<queue>
using namespace std;
class stack{
    queue<int>q1;
    queue<int>q2;
    public:
    void push(int val){
        q1.push(val);
    }
    void pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(q2.size()!=0){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int peek(){
        int final;
        final=q1.back();
        return final;
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
    s.pop();
    cout<<s.peek()<<endl;
    return 0;
}
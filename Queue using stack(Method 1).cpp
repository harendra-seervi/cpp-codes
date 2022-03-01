#include<iostream>
#include<stack>
using namespace std;
class queue{
    stack<int>st1;
    stack<int>st2;
    public:
    void push(int val){
        st1.push(val);
    }
    void pop(){
        while(st1.empty()!=true){
            int x=st1.top();
            st2.push(x);
            st1.pop();
        }
        st2.pop();
        while(st2.empty()!=true){
            int x=st2.top();
            st1.push(x);
            st2.pop();
        }
    }
    int peek(){
        while(st1.empty()!=true){
            int x=st1.top();
            st2.push(x);
            st1.pop();
        }
        int final =st2.top();
        while(st2.empty()!=true){
            int x=st2.top();
            st1.push(x);
            st2.pop();
        }
        return final;
    }
    bool empty(){
        if(st1.empty()==true && st2.empty()==true) return true;
        return false;
    }
};
int main() {
    queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout<<a.peek()<<endl;
    a.pop();
    cout<<a.peek()<<endl;
return 0;
}

// #include<iostream>
// using namespace std;
// int n=20;
// class stack{
//     public:
//     int *arr;
//     int top;
//     stack(){
//         top=-1;
//         arr=new int [n];
//     }
//     void enque(int val){
//         if(top==n-1){
//             cout<<"stack overflow"<<endl;
//             return;
//         }
//         top++;
//         arr[top]=val;
//     }
//     void pop(){
//         if(top==-1){
//             cout<<"stack is empty"<<endl;
//             return ;
//         }
//         top--;
//     }
//     int  peek(){
//         if(top==-1){
//             cout<<"stack is em"<<endl;
//             return -1;
//         }
//         return arr[top];
//     }
//     bool empty(){
//         if(top==-1){
//             return true;
//         }
//         return false;
//     }
//     void deque(stack &q){
//         stack temp;
//         while(q.top!=-1){
//             int x=q.peek();
//             q.pop();
//             temp.enque(x);

//         }
//         temp.pop();
//         while(temp.top!=-1){
//             int x=temp.peek();
//             q.enque(x);
//             temp.pop();
//         }
//     }
// };

// int main(){
//     stack q;
//     q.enque(1);
//     q.enque(2);
//     q.enque(3);                                 
//     q.deque(q);
//     while(q.top!=-1){
//         cout<<q.peek()<<endl;
//         q.pop();
//     }
// return 0;
// }
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return ;
    }
    int ele=st.top();
    st.pop();
    insertAtBottom(st,val);
    st.push(ele);
}

void rev(stack<int>&st){
    if(st.size()==0){
        return;
    }
    int ele=st.top();
    st.pop();
    rev(st);
    insertAtBottom(st,ele);
}
int main() {
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    rev(st);
    while(st.empty()!=true){
        cout<<st.top()<<endl;
        st.pop();
    }
return 0;
}
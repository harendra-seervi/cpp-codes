#include<bits/stdc++.h>
using namespace std;
void p(stack<int>&st){
    if(st.size()==1){
        st.pop();
        return ;
    }
    int x=st.top();
    st.pop();
    p(st);
    st.push(x);
}
int main() {
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    p(st);
    while(st.empty()!=true){
        cout<<st.top()<<endl;
        st.pop();
    }
return 0;
}
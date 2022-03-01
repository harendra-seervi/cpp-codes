#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int ans;
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        char ch=s[i];
        if(s[i]=='+'||s[i]=='/'||s[i]=='*'||s[i]=='-'){
            int op3;
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            if(s[i]=='+'){
                op3=op1+op2;
            }
            if(s[i]=='-'){
                op3=op1-op2;
            }
            if(s[i]=='*'){
                op3=op1*op2;
            }
            if(s[i]=='/'){
                op3=op1/op2;
            }
            st.push(op3);
        }
        else{
            st.push(s[i]-'0');
        }
    }
    ans=st.top();
    cout<<ans<<endl;    
return 0;
}
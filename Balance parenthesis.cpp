#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    stack<char>st;
    bool check=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('|| s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(st.empty()==true){
                    check=true;
                    break;
                }
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    check=true;
                    break;
                }
            }   
            else if(s[i]=='}'){
                if(st.empty()==true){
                    check=true;
                    break;
                }
                if(st.top()=='{'){
                    st.pop();
                }
                else{
                    check=true;
                    break;
                }
            }
            else if(s[i]==']'){
                if(st.empty()==true){
                    check=true;
                    break;
                }
                if(st.top()=='['){
                    st.pop();
                }
                else{
                    check=true;
                    break;
                }
            }
        }
    }
    if(check==true|| st.empty()!=true){
        cout<<"Unbalanced paranthsis"<<endl;
    }
    else{
        cout<<"Balanced paranthasis"<<endl;
    }
return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    stack<char>st;
    bool check=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]== '+'){
            st.push(s[i]);  
        }
        if(s[i]==')'){
            if(st.empty()!=true){
                if(st.top()=='('){
                    check=true;
                }
            }
            while(st.empty()!=true && st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }
    if(check==true) cout<<"Reductent pranthesis"<<endl;
    else  cout<<"Not a Reductent pranthesis"<<endl;
return 0;
}
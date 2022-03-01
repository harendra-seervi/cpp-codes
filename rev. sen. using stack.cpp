#include<bits/stdc++.h>
using namespace std;
void rev(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i]; 
            i++;
        }
        st.push(word);
    }
    while(st.empty()!=true){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main() {
    string s;
    getline(cin,s);
    rev(s);
return 0;
}
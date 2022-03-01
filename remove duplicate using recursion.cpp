#include<bits/stdc++.h>
using namespace std;
void dup(string s,int i){
    if(i==s.size()-1){
        cout<<s;
        return;
    } 
    if(s[i]==s[i+1]){
        s.erase(i,1);
        i--;
    }
    dup(s,i+1);
}
int main(){
    string s;
    cin>>s;
    dup(s,0);
    return 0;
}                   
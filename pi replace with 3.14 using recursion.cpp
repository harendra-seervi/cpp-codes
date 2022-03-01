#include<bits/stdc++.h>
using namespace std;
void rep(string s,int si){
    if(si==0){
        cout<<s;
        return;
    }
    if(s[si]=='i'&&s[si-1]=='p'){
        s.erase(si-1,2);
        s.insert(si-1,"3.14");
    }
    rep(s,si-1);
}
int main(){
    string s;
    cin>>s;
    rep(s,s.size()-1);
    return 0;
}
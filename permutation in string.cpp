#include<bits/stdc++.h>
using namespace std;
void permutation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
       char ch=s[i]; 
        string rem=s.substr(0,i)+s.substr(i+1);   
        permutation(rem,ans+ch);
    }
}
int main() {
    string s;
    cin>>s;
    permutation(s,"");
return 0;
}
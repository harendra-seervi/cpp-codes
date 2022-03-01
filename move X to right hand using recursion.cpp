#include<bits/stdc++.h>
using namespace std;
void rem(string s,string t,int i){
   if(i==s.size()-1){
       cout<<s+t;
       return;
   }
   if(s[i]=='x'){
       t.push_back(s[i]);
       s.erase(i,1);
       i--;
   }
   rem(s,t,i+1);
}
int main() {
    string s;
    cin>>s;
    string t;
    rem(s,t,0);
return 0;
}
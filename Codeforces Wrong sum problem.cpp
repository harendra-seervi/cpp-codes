#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod  1000000007
int main(){
    ll t;
    cin>>t;
    while(t>0){
        string a;
        string s;
        cin>>a>>s;
        a="0000000000000000000000000000000000000000000"+a;
        s="000000000000000000000000000000000000000000000"+s;
        ll i=a.size()-1;
        ll j=s.size()-1;
        string ans;
        while(i>=0 && j>=0){
            ll sing=s[j]-'0';
            string pk;
            pk.push_back(s[j-1]);
            pk.push_back(s[j]);
            ll doub=stoi(pk);
            ll aval=a[i]-'0';
            bool check=false;
            for(ll k=0;k<=9;k++){
                if(aval+k == sing){
                    string ttt=to_string (k);
                    ans=ans+ttt;
                    check=true;
                    j=j-1;
                    break;
                }
                if(aval +k == doub){
                    string ttt=to_string (k);
                    ans=ans+ttt;
                    check=true;
                    j=j-2;
                    break;
                }
            }
            i=i-1;
            if(check==false){
                ans.clear();
                ans="1-";
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        ll st=0;
        while(ans[st]=='0'){
            st=st+1;
        }
        for(ll l=st;l<ans.size();l++){
            cout<<ans[l];
        }
        cout<<endl;
    t--;
    }
    return 0;
}
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(string &s,vector<string>&v,string temp,int ind){
        if(ind>=s.size()-1){
            temp.push_back(s[ind]);
            v.push_back(temp);
            return;
        }
        temp.push_back(s[ind]);
        solve(s,v,temp,ind+1);
        temp.push_back(' ');
        solve(s,v,temp,ind+1);
    }
    vector<string> permutation(string s){
        // Code Here
        vector<string>v;
        string temp="";
        solve(s,v,temp,0);
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends
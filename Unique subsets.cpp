#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void solve(vector<int>&arr,set<vector<int>>&s,int ind,vector<int>&ans){
        if(ind>arr.size()) return;
        if(ind==arr.size()){
            s.insert(ans);
            return;
        }
        ans.push_back(arr[ind]);
        solve(arr,s,ind+1,ans);
        ans.pop_back();
        solve(arr,s,ind+1,ans);
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n){
        sort(arr.begin(),arr.end());
        vector<int>ans;
        set<vector<int>>s;
        solve(arr,s,0,ans);
        vector<vector<int>>final;
        for(auto val:s){
            vector<int>x=val;
            final.push_back(x);
        }
        return final;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> leafNodes(int pre[],int n) {
        int in[n];
        for(int i=0;i<n;i++){
            in[i]=pre[i];
        }
        sort(in,in+n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({in[i],i});
        }
        vector<int>v;
        int st=0;
        int end=n-1;
        solve(pre,in,st,end,v,mp);
        return v;
    }
    int ind=0;
    void solve(int pre[],int in[],int st,int end,vector<int>&v,unordered_map<int,int>&mp){
        if(st>end){
            return;
        }
        int mid=mp[pre[ind++]];
        if(st==end){
            v.push_back(in[mid]);
            return;
        }
        solve(pre,in,st,mid-1,v,mp);
        solve(pre,in,mid+1,end,v,mp);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
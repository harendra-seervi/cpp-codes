#include<bits/stdc++.h>
using namespace std;
    
// Tip to avoid bugs.
/*
  *Think twice before code
*/
bool mycmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.second!=p2.second){
        return p1.second>p2.second;
    }
    else{
        return p1.first>p2.second;
    }

}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>>v;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto val:mp){
        v.push_back(make_pair(val.first,val.second));
    }
    sort(v.begin(),v.end(),mycmp);
    for(int i=0;i<v.size();i++){
        int x=v[i].second;
        for(int j=0;j<x;j++){
            cout<<v[i].first<<" ";
        }
    }
}
    
int main(){
    solve();
return 0;
}
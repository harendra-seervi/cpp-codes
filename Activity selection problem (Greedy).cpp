#include<bits/stdc++.h>
using namespace std;
bool mycompair(pair<int,int>p1,pair<int,int>p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int f,s; cin>>f>>s;
        v.push_back({f,s});
    }
    sort(v.begin(),v.end(),mycompair);
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    int ct=1;
    int i=0;
    int j=1;
    while(i<n && j<n){
        if(v[i].second<v[j].first){
            ct++;
            i=j;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<ct<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        pq.push(ele);
    }
    int sum=0;
    int ct=0;
    while(pq.empty()!=true){
        ct++;
        sum+=pq.top();
        if(sum>=k) break;
        pq.pop();
    }
    cout<<ct<<endl; 
return 0;
}
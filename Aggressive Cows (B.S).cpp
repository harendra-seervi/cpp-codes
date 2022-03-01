#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool ispossiable(int arr[],int n,int mid,int k){
    int ct=1;
    int pre=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-pre>=mid){
            ct++;
            pre=arr[i];
        }
        if(ct==k){
            return true;
            break;
        }
    }
    return false;
}
void solve(int arr[],int n,int k){
    int lo=1;
    int hi=arr[n-1]-arr[0];
    int res=-1;
    while(hi>=lo){
        int mid=(hi+lo)/2;
        if(ispossiable(arr,n,mid,k)){
            res=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    cout<<res<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int k;
    cin>>k;
    solve(arr,n,k);
    return 0;
}
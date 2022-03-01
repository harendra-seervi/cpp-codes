#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int arr[],int n,int k){
    int sum=0;
    if(k>=n){
        cout<<"not exist "<<endl;
        return;
    }
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    if(sum%3==0){
        cout<<"0"<<" "<<k<<endl;
        return;
    }
    for(int i=k;i<n;i++){
        sum+=arr[i];
        sum=sum-arr[i-k];
        if(sum%3==0){
            cout<<i-k+1<<" "<<i<<endl;
            return;
        }
    }
    cout<<"not exist"<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    solve(arr,n,k);
    return 0;
}
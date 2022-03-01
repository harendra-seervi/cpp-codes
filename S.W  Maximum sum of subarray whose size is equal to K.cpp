#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n,int k,int x){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int ans=-1;
    if(sum<x){
        if(sum>ans) ans=sum;
    }
    int st=0;
    for(int i=k;i<n;i++){
        sum=sum+arr[i];
        sum=sum-arr[st];
        st++;
        if(sum<x){
            if(sum>ans) ans =sum;
        }
    }
    return ans;
}
// find maximum sum of subarray whose size is k
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int k;
    cin>>k;
    cout<<solve(arr,n,k,x)<<endl;
return 0;
}
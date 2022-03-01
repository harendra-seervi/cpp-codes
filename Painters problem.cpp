#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// 4
// 10 20 30 40
// 2
//ans => 60
bool ispossiable(int arr[], int mid, int n,int k){

    int stu=1; 
    int ctpages=0; 
    for(int i=0;i<n;i++){
        if((ctpages+arr[i])<=mid){
            ctpages+=arr[i];
        }
        else{
            stu++;
            ctpages=arr[i];
        }
    }

    if(stu<=k){
        return true;
    }
    return false;
}

void solve(int arr[],int n,int k){
    int lo=arr[0];
    int hi=0;
    for(int i=0;i<n;i++){
        hi+=arr[i];
    }
    int ans=-1;
    while(hi>=lo){
        int mid=(hi+lo)>>1;
        if(ispossiable(arr,mid,n,k)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
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
    sort(arr,arr+n);
    solve(arr,n,k);
    return 0;
}
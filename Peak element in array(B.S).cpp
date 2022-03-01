#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n){
    int hi=n-1;
    int lo=0;
    while(hi>=lo){
        int mid=lo+(hi-1)/2;
        if(mid>0 && mid<n-1){
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]){
                lo=mid+1;
            }
            else if(arr[mid]>arr[mid+1]){
                hi=mid-1;
            }
        }
        if(mid==0){
            if(arr[0]>arr[1]) return 0;
            else return 1;
        }
        if(mid==n-1){
            if(arr[n-1]>arr[n-2]) return n-1;
            else return n-2;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n)<<endl;
return 0;
}
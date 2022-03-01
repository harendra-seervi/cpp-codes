#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){
    int i=n-1;
    sort(arr,arr+n);
    int count=0;
    while(i>=2){
        int r=i-1;
        int l=0;
        while(l<r){
            if(arr[l]+arr[r]>arr[i]){
                count+=(r-l);
                r--;
            }
            else{
                l++;
            }
        }
        i--;
    }
    cout<<"The number of possible triangle in a given array is:- ";
    cout<<count<<endl; 
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
return 0;
}
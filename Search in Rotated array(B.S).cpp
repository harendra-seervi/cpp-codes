#include<bits/stdc++.h>
using namespace std;
int bs(int arr[],int n,int tar){
    int hi=n-1;
    int lo=0;
    while(hi>=lo){
        int mid=(hi+lo)/2;
        if(arr[mid]==tar){
            return mid;
        }
        else if(arr[lo]<=arr[mid]){
            //left part is sorted
            if(tar>=arr[lo] && tar<arr[mid]){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        else if(arr[mid]<=arr[hi]){
            //right part is sorted
            if(tar>arr[mid] && tar<=arr[hi]){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
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
    int key;
    cin>>key;
    int ind=bs(arr,n,key);
    cout<<ind<<endl;
return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 6
// 2 3 5 1 1 5
// 4

bool ispalindrome(int num){
    int temp=num;
    int rev=0;
    while(temp>0){
        int ld=temp%10;
        rev=rev*10+ld;
        temp=temp/10;
    }
    if(rev==num) return true;
    return false;
}

int solve(int arr[],int n,int k){
    int num=0;
    for(int i=0;i<k;i++){
        num=(num*10)+arr[i];
    }
    if(ispalindrome(num)){
        return 0;
    }
    for(int i=k;i<n;i++){
        num=((num%(int )pow(10,k-1))*10)+arr[i];
        if(ispalindrome(num)){
            return i-k;
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
    int k;
    cin>>k;
    int f=solve(arr,n,k);
    if(f==-1){
        cout<<"not found"<<endl;
        return 0;
    }
    for(int i=f+1;i<f+1+k;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
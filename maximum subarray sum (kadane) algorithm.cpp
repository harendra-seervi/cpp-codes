#include<iostream>
#include<climits>
using namespace std;
int kadane(int arr[],int n){
    int current=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        current+=arr[i];
        if(current<0){
            current=0;
        }
        maxsum=max(current,maxsum);
    }
    return maxsum;
}
int final(int arr[],int n){
    int check =0;int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            check=1;
        }
        maxsum=max(maxsum,arr[i]);
    }
    if(check==0){
        return maxsum;
    }
    else{
        int wrapsum=0;
        int nonwrapsum=kadane(arr,n);
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=arr[i];
            arr[i]=-arr[i];
        }
        wrapsum=totalsum+kadane(arr,n);
        int final=INT_MIN;
        final=max(wrapsum,nonwrapsum);
        return final;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<final(arr,n);
    return 0;
}
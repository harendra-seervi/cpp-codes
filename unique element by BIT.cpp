#include<bits/stdc++.h>
using namespace std;
int cheack(int n,int k){
    return n^k;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool t=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(cheack(arr[i],arr[j])==0){
                t=true;
            }
        }
        for(int k=i+1;k<n;k++){
            if(cheack(arr[i],arr[k])==0){
                t=true;
            }
        }
        if(t==false){
            cout<<i<<" is a unique element in the given array"<<endl;
        }
        t=false;
    }
return 0;
}
#include<bits/stdc++.h>
using namespace std;

// 8
// 28 2 3 6 496 99 8128 24
// 4


int f[9]={0};
bool isperfact(int a){
    if(f[a]==1) return true;
    return false;
}
void solve(int arr[],int n,int k){
    int cpn=0; //count perfact number till now
    for(int i=0;i<k;i++){
        if(isperfact(i)){
            ++cpn;
        }
    }
    int maxicpn=-1;
    if(cpn>maxicpn){
        maxicpn=cpn;
    }
    for(int i=k;i<n;i++){
        if(isperfact(i)){
            cpn++;
        }
        if(isperfact(i-k)){
            cpn--;
        }
        if(cpn>maxicpn){
            maxicpn=cpn;
        }
    }
    if(maxicpn==-1){
        cout<<"perfact number is not found in array"<<endl;
    }
    else{
        cout<<maxicpn<<endl;
    }
}
void fillarray(int arr[],int n){
    for(int i=0;i<n;i++){
        int val=arr[i];
        int sum=0;
        for(int j=1;j<arr[i];j++){
            if(val%j==0){
                sum+=j;
            }
        }
        if(sum==val){
            f[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    fillarray(arr,n);
    int k;
    cin>>k;
    solve(arr,n,k);
return 0;
}
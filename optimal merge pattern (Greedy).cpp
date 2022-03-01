#include<bits/stdc++.h>
using namespace std;
// 4
// 5 2 4 7
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum=arr[0]+arr[1];
    int ts=0;
    ts=ts+sum;
    for(int i=2;i<n;i++){
        sum+=arr[i];
        ts=ts+sum;
    }
    cout<<ts<<endl;

return 0;
}
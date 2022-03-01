#include<iostream>
#include<climits>
using namespace std;
void solve(int arr[],int n,int x){
    int st=0;
    int minlength =n+1;
    int i=0;
    int sum=0;
    while(i<n){
        while(sum<=x && i<n){
            sum+=arr[i];
            i++;
        }
        while(sum>x && st<=i){
            minlength=min(minlength,(i-st));
            sum=sum-arr[st];
            st++;
        }
    }
    cout<<minlength<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    solve(arr,n,x);
    return 0;
}
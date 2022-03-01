#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int n; long long int q;
    cin>>n>>q;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(q>0){
        long long int num,l,r,x,y;
        cin>>num;
        if(num==1){
            cin>>l>>r>>x;
            for(int i=l-1;i<=r-1;i++){
                arr[i]=arr[i]+((x+i+1-l)*(x+i+1-l));
            }
        }
        if(num==2){
            cin>>y;
            cout<<arr[y-1]<<endl;
        }
        q--;
    }
   return 0; 
}
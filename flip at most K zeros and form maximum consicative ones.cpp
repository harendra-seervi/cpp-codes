#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=0;
    int z=0;
    int k;
    int maxi=0;
    cin>>k;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            z++;
        }
        while(z>k){
            j++;
            if(arr[j]==0){
                z--;
            }
        }
        maxi=max(maxi,i-j);

    }
    cout<<maxi<<endl;
return 0;
}
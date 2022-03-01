#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int pd=array[1]-array[0];
    int current =2;
    int ans =2;
    for(int j=2;j<n;j++){
        if(pd==array[j]-array[j-1]){
            current++;
        }
        else{
            pd=array[j]-array[j-1];
            current=2;
        }
        ans=max(current,ans);
    }
    cout<<ans<<endl;
return 0;
}
#include<iostream>
using namespace std;
int tilingway(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilingway(n-1)+tilingway(n-2);
}
int main(){
    int n;  
    cin>>n;
    cout<<tilingway(n);
    return 0;
}
#include<iostream>
using namespace std;
int catlan(int n){
    int res=0;
    for(int i=0;i<n;i++){
        res+= catlan(i)*catlan(n-i-1);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<catlan(i)<<endl;
    }
    return 0;
}
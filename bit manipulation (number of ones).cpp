#include<iostream>
using namespace std;
int check(int n){
    return (n)&(n-1);
}
int main(){
    int n;
    int count =0;
    cin>>n;
    while(n>0){
        n=check(n);
        count++;    
    }
    cout<<count<<endl;
    return 0;
}
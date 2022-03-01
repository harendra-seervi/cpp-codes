#include<iostream>
using namespace std;
int t=0;
int reverse(int n){
    while(n>0){
        int lastdegit=n%10;
        t=t*10+(lastdegit);
        n=n/10;
    }
    return t;
}
int main(){
    int n;
    cin>>n;
    int sum=0;
    while(n>0){
        int reminder=n%2;
        n=n/2;
        sum=sum*10+(reminder);
    }
    reverse(sum);
    cout<<sum;
    return 0;
}
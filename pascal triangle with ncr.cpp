#include<iostream>
using namespace std;
int factorial(int t){
    int sum=1;
    for(int r=1;r<=t;r++){
        sum=sum*r;
    }
    return sum;
}
int ncr(int n,int r){
    int t;
    t=factorial(n)/(factorial(n-r)*factorial(r));
    return t;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j);
        }
    cout<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int check(int n){
    return(n&(n-1));
}
int main(){
    int n;
    cin>>n;
    if(check(n)==0){
        cout<<"the number is power of 2"<<endl;
    }
    else{
        cout<<"the number is not power of 2"<<endl;
    }
    return 0;
}
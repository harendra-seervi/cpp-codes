#include<iostream>
using namespace std;
bool isprime (int num){
    for(int j=2;j<num;j++){
        if(num%j==0){
            return false;
        }
    }
    return true;
}
int main() {
    int a,b;
    cin>>a>>b;
    int i;
    for(i=a;i<=b;i++){
        if(isprime(i)){
            cout<<i<<endl;
        }
    }
return 0;
}
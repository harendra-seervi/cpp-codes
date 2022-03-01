#include<iostream>
using namespace std;
int hcf(int a,int b){
    int reminder=0;
    while(b>0){
        reminder=a%b;
        a=b;
        b=reminder;
    }
return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<hcf(a,b)<<endl;
    return 0;
}
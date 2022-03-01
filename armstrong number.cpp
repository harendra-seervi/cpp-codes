#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n;    
    int sum=0;
    cin>>n;
    int orignaln=n;
    while (n!=0){
        int lastdegit =(n%10);         
        sum=(sum)+(lastdegit^3);
        cout<<sum<<endl;
        n=n/10;
    }
    if (sum==orignaln){
        cout<<"armstrong number"<<endl;
    }
    if(sum!=orignaln){
        cout<<"not an armstrong number"<<endl;
        cout<<sum<<endl;

    }
return 0;
}
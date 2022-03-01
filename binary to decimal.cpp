#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    int q=0;
    while(n>0){
        int lastdegit =n%10;
        sum=sum+((lastdegit)*(pow(2,q)));
        n=n/10;
        q++;
    }
    cout<<sum<<endl;
    return 0;
}

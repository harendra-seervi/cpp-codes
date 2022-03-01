#include<bits/stdc++.h>
using namespace std;
int calones(int n){
    return n&(n-1);
}
int main() {
    int n;
    cin>>n;
    int count=0;
    while (n>0)
    {
        n=calones(n);
        count++;
        /* code */
    }
    cout<<count<<endl;
    
return 0;
}
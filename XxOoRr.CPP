//x00rr codechef


#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t>0){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int& i: a){
            cin>>i;
        }
        vector<int>nbit(31);
        int c,t1;
        for(int j=0;j<=30;j++){
            c=0;
            for(int&i:a){
                if(i%2!=0){
                    c++;
                }
                i/=2;
            }
            nbit[j]=c;
        }
        int ans=0;
        for(int j=0;j<=30;j++){
            if(nbit[j]%k==0){
                ans+=nbit[j]/k;

            }
            else{
                ans+=nbit[j]/k +1;
            }
        }
        cout<<ans<<endl;
    t--;
    }
    return 0;
}
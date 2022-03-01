#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m,c=0,mc=0,i,j;
        cin>>n>>m;
        string str;
        
        for(i=0;i<n;i++)
        {
            cin>>str;
            for(j=0;j<m;j++)
            {
                if(str[j]=='1')
                c++;
            }
            if(c%2!=0)
            mc++; 
            c=0; 
        }
        if(mc%2==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
        
    }
    
    return 0;
}
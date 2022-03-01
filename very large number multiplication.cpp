// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       bool minn=false;
       bool one=false;
       bool two =false;
       for(int c=0;c<s1.size();c++){
           if(s1[c]=='-'){
               minn=true;
               one=true;
               s1.erase(c,1);
               c--;
           }
       }
       for(int c=0;c<s2.size();c++){
           if(s2[c]=='-'){
               minn=true;
               two=true;
               s2.erase(c,1);
               c--;
           }
       }
       if(one==two&& one==true){
           minn=false;
       }
       //Your code h
       int n=s1.size()+s2.size();
       int arr[n]={0};
       int k=n-1;
       int pf=0;
       int i=s1.size()-1;
       int j=s2.size()-1;
       int carray=0;
       int carray2=0;
       while(j>=0){
           while(i>=0){
               int pro=((s1[i]-'0')*(s2[j]-'0'))+carray+carray2;
               int temp=(arr[k]+(pro%10));
               carray2=(temp/10);
               arr[k]=(temp%10);
               carray=pro/10;
               k--;
               i--;
           }
         
           arr[k]=arr[k]+carray+carray2;
           carray2=0;
           pf++;
           carray=0;
           k=(n-1)-(pf);
           i=s1.size()-1;
           j--;
       }
       string ans;
       bool check=false;
       for(int c=0;c<n;c++){
           if(check==true && arr[c]==0){
               string final=to_string(arr[c]);
               ans+=final;
           }
           else if(arr[c]!=0){
               check=true;
               string final=to_string(arr[c]);
               ans+=final;
           }
       }
       if(ans.size()==0){
           return "0";
       }
       if(minn==true){
           string m="-";
           m=m+ans;
           return m;
       }
       return ans;
    
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends
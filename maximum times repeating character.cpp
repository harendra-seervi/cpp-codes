#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int n=100;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
    
    char ans;
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
    }
    int maxno=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxno<arr[i]){
            maxno=arr[i];
            ans='a'+i-32;
        }
    }

    cout<<"The maximum repeating character is "<<ans<<endl;
    cout<<"frequency of repeating character is "<<maxno<<endl;
    return 0;
}
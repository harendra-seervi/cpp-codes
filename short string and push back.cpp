#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="abBcDtrjieyT";
    string t;
    string y;
    int r=0;
    int u=0;
    for(int i=0;i<s.length();i++){
        if(s[i]-'a'>=0){
            t.push_back(s[i]);
            r++;
        }
        else{
            y.push_back(s[i]);
            u++;
        }
    }
    sort(t.begin(),t.end());
    sort(y.begin(),y.end());
    cout<<t<<endl;
    cout<<y<<endl;
       return 0;
}
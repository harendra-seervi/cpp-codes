#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s="55965296";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s;
    return 0;
}
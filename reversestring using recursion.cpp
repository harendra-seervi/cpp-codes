#include<iostream>
#include<string>
using namespace std;
void reverses(string s){
    if(s.size()==0){
        return;
    }
    string rest=s.substr(1);
    reverses(rest);
    cout<<s[0];
}
int main(){
    string s="harendra";
    reverses(s);
    return 0;
}
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//     string s="abcdefghijklmnopqrstuvwxyz";
//     for(int i=0;i<s.length();i++){
//         if(s[i]>='a'&&s[i]<='z'){
//             s[i]=s[i]-32;
//         }
//     }
//     cout<<s<<endl;
//     return 0;
// }
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s="abcdefghijklmnopqrstuvwxyz";
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s<<endl;
    cout<<endl;  
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s<<endl;
    return 0;
}
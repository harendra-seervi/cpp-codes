
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s="85917";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
    return 0;
}
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;
// int main(){
//     string s="53214";
//     for(int i=0;i<s.size()-1;i++){
//         for(int j=i+1;j<s.size();j++){
//             if(s[i]<s[j]){
//                 int temp=s[j];
//                 s[j]=s[i];
//                 s[i]=temp;
//             }
//         }
//     }
//     cout<<s<<endl;
//     return 0;
// }
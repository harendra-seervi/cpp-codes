#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter the number "<<endl;
    cin>>a>>b>>c;
    if(a>b){
        if(a>c){
            cout<<a<<" is max"<<endl;
            
        }
        else{
            cout<<c<<" is max"<<endl;

        }
    
    }
    if(b>a){
        if(b>c){
            cout<<b<<" is max"<<endl;

        }
        else{
            cout<<c<<" is max"<<endl;
        }
    }
      
    return 0;

}
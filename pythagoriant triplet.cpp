#include<iostream>
using namespace std;
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b>c||a>c>b){
        if(a*a==b*b+c*c){
            cout<<"this is an pythagoriant triplet"<<endl;
        }
        else{
            cout<<"this is not an pythagoriant trip"<<endl;
        }
    }

     if(b>a>c||b>c>a){
        if((b*b)==a*a+c*c){
            cout<<"this is an pythagoriant triplet"<<endl;
        }
        else{
            cout<<"this is not an pythagoriant trip"<<endl;
        }
    }

        else{
        if((c*c)==a*a+b*b){
            cout<<"this is an pythagoriant triplet"<<endl;
        }
        else{
            cout<<"this is not an pythagoriant trip"<<endl;
        }
    }

    
return 0;
}
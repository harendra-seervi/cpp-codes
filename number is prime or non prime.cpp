#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  bool a=true;
  for(int i=2;i<n;i++){
    if(n%i==0){
      a=false;
    }
  }
  if(a==false){
    cout<<"this number is a non prime number "<<endl;
  }
  else{
    cout<<" given number is an prime number "<<endl;
  }
  return 0;
}
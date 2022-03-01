#include<iostream>
using namespace std;
void check(int arr[],int n){
    bool t=false;
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           if (((arr[i])^(arr[j]))==0){
               t=true;
           }
       }
       for(int j=0;j<i;j++){
           if (((arr[i])^(arr[j]))==0){
               t=true;
           }
       }
       if(t==false){
           cout<<arr[i]<<endl;
       }
       t=false;
    }
}
int main() {
    int arr[10]={2,5,8,5,8,7,1,2,1,13};
     check(arr,10);
return 0;
}
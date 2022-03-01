#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int maxno=INT_MIN;
    int j;
    for(int i=0;i<n;i++){
         j=max(array[i],maxno);
    }
    cout<<"this is maximum number of an given array "<<j<<endl;
     
    return 0; 
}
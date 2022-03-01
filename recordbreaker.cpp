#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int maxno=-1;
    for(int i=0;i<n;i++){
        maxno=max(array[i],maxno);
        if(maxno<=array[i]&&array[i]>array[i+1]){
            cout<<i<<" is an record breaking day"<<endl;
        }
    }
    return 0; 
}
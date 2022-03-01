#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]>array[j]){
                int temp =array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
    int minno=1000;
    for(int i=0;i<n;i++){
        if((array[i]>0)&&((array[i]+1)!=(array[i+1]))){
            minno=min(minno,array[i]+1);
        }
    }
    cout<<" the smallest positive missing  intiger in the given array is "<<minno<<endl;
    return 0;
}
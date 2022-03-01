#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<" Enter the value of the indux of matrix 1"<<endl;
    cin>>a>>b;
    cout<<" enter the element of the matrix"<<endl;
    int arr1[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<" enter the value of indux of matrix 2"<<endl;
    int c,d;
    cin>>c>>d;
    int arr2[c][d];
    cout<<" enter the element of the matrix "<<endl;
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            cin>>arr2[i][j];
        }
    } 
    int currentsum=0;
    int final[a][d];
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<b;k++){
                currentsum=currentsum+arr1[i][k]*arr2[k][j];
            }
            final[i][j]=currentsum;
            currentsum=0;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
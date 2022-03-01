#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    int currentlength=0;int previous_length=0;
    int i=0;
    int st=0;
    int end=0;
    while(1){
        if(arr[i]==' '||arr[i]=='\0'){
            if(currentlength>previous_length){
                previous_length=currentlength;
                end=st;
            }
            st=i+1;
            currentlength=0;
        }
        else{ 
            currentlength++;
        }
        if(arr[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<" maximum length of the word is "<<previous_length<<endl;
    cout<<endl;
    for(int i=0;i<previous_length;i++){
        cout<<arr[i+end];
    }
    return 0;
}
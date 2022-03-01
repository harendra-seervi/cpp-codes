// #include<iostream
// using namespace std;
// int main(){
//     int a=10;
//     int *apointr=&a;
//     *apointr=20;
//     cout<<apointr<<endl;
//     cout<<*apointr<<endl;
//     cout<<&a<<endl;
//     return 0;
// }
//
//--------------------------------------------------------------
    
//               // POINTER TO AIRTHMATIC //
// #include<iostream>
// using namespace std;
// int main(){
//     int a=10;
//     int *apointer=&a;        //EXAMPLE
//     cout<<apointer<<endl;     //2000
//     apointer++;            
//     cout<<*apointer<<endl;    //2004
//     return 0;
// }

//--------------------------------------------------------------
//
//               //POINTER TO ARRAY //
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={10,20,30};
//     int *apointer=arr;
//     for(int i=0;i<3;i++){
//         cout<<*(arr+i)<<endl;
//     }
//     return 0;
// }

//-----------------------------------------------
#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a=10;
    int b=11;
    int *apointer=&a;
    int *bpointer=&b;
    swap(apointer,bpointer);
    cout<<a<<" and "<<b<<endl;
    return 0;
}
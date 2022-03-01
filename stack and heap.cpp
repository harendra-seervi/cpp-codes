#include<iostream>
using namespace std;
int main(){
    int a=10;
    int *p=new int();
    *p=10;
    delete(p);
    p=new int[5];
    delete[]p;
    p=  NULL;
    return 0;
}
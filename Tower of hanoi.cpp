#include<bits/stdc++.h>
using namespace std;
int t=0;
void towerofhannoi(int n,char src,char des,char helper){
    if(n==0){  
        return ;
    }
    towerofhannoi(n-1,src,helper,des);
    t++;
    cout<<"Move from "<< src<<" to "<<des<<endl;
    towerofhannoi(n-1,helper,des,src);
}
int main() {
    towerofhannoi(3,'A','C','B');
    cout<<t<<endl;
return 0;
}
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
    const int N=8;
    int indux[N];
    for(int i=0;i<n;i++){
        indux[i]=-1;
    }
    int ans =INT_MAX;
    for(int i=0;i<n;i++){
        if(indux[array[i]]!=-1){
            ans =min(ans ,indux[array[i]]);
        }
        else{
            indux[array[i]]=i;
        }
    }
    cout<<ans +1<<" is the minimum indux of repeatative element "<<endl;
    return 0;
}


// #include<iostream>
// #include<climits>
// using namespace std;
// int main(){
//     // #ifndef ONLINE_JUDGE
//     //     // freopen("input.txt", "r", stdin);
//     //     // freopen("output.txt", "w", stdout);
//     // #endif
//     int n; 
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){
//         cin>>array[i];
//     }
//     const int N =1e6+2;
//     int indux[N];
//     for(int i=0;i<N;i++){
//         array[i]=-1;
//     }
//     int minno=INT_MAX;
//     for(int i=0;i<n;i++){
//         if(indux[array[i]]!=-1){
//             minno=min(minno,indux[array[i]]);
//         }
//         else{
//             indux[array[i]]=i;
//         }
//     }
//     cout<<minno<<endl;
//     return 0;
// }




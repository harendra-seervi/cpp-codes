#include<bits/stdc++.h>
using namespace std;
int main() {

    //++++++++++++++++++++++++++++++++++++++++[VECTOR]+++++++++++++++++++++++++++++++++++++
    cout<<"____________________________________vector_____________________"<<endl;cout<<endl;






    vector<int>v={1,2,3,4,5};
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    // auto tt=find(v.begin(),v.end(),2);
    // cout<<*tt<<endl;
    auto ii=find(v.begin(),v.end(),44);
    if(ii==v.end()) cout<<"not found"<<endl;            //*** ((find))    function
    else   cout<<"found"<<endl;
    cout<<endl;


    //-------------making itratior-----------
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();++it){                  // it++ or it+1 dono me difference hi 
        cout<<*it<<" ";                                  //vector me to theek hi but MAPS me problem                              
    }                                                    //hone wali hi 
    vector<pair<int,int>>arr={{1,3},{2,4},{5,8}};
    vector<pair<int,int>>::iterator itr;
    cout<<endl;
    for(itr=arr.begin();itr!=arr.end();++itr){
        cout<<itr->first<<" "<<itr->second<<endl;       // Dyan rakne wali baat-- (*it).first==it->first
    }

    //--------------range based ---------------

    for(int val:v){
        cout<<val<<" ";                                  // copy wala scene
    }
    cout<<endl;
    for(int &val:v){
        cout<<val<<" ";                                 // by reference wala scene
    }
    cout<<endl;
    for(pair<int,int> &val:arr){
        cout<<val.first<<" "<<val.second<<endl;         // vector pair me range based
    }
    //-------------auto ka mehetav--------------
    for(auto &val:v){
        cout<<val<<" ";                                // auto kisi bhi datatype ko maan sakte hii
    }                                                  // jese line no. 35 me vo int ka kaam kar raha hi
    for(auto &val:arr){                                // or line no. 38 me pair<int,int> ka kaam kar raha hi
        cout<<val.first<<" "<<val.second<<endl;       
    }









    //+++++++++++++++++++++++++++++++++++++++++  [MAPS]   ++++++++++++++++++++++++++++++++++++++++++
    cout<<"________________________________________MAP___________________________________________"<<endl;
    

    // Tree se impliment hote hi ye guys
    map<int,string>m;
    m.insert(make_pair(1,"harendra"));
    m.insert(make_pair(3,"rahul"));                   //***  ((insertion))   ki TC=o(long(N));
    m.insert(make_pair(2,"rakesh"));                       
    m.insert(make_pair(4,"neha"));                       
    for(auto &val:m){
        cout<<val.first<<" "<<val.second<<endl;        // MAPS hamesha sorted order me print karte hi
    }


    auto ittr=m.find(3);                               //*** ((find))    function  hamesha itration return karta hi  TC=log(N)
    cout<<ittr->second<<endl;                          //                or agar usse element nahi mila to itr.end() pradhan karega


    m.erase(ittr);
    for(auto &val :m){
        cout<<val.first<<" "<<val.second<<endl;       //***  ((erase))    iss fuction me vo itrator bhi dal sakte hi or key bhi
    }





    //++++++++++++++++++++++++++++++++++++++++  [UNORDERD_MAPS]   ++++++++++++++++++++++++++++++++++++++++++
    cout<<"______________________________________UNORDERD_MAP_____________________________________"<<endl;


    // Hash table se impliment hote hi ye guys
    // basic datatype ko lee sakte hi complex datatype ko key me nahi lee sakte hi kiyo ki unke hash value define nahi hote hi islea
    // Tc insertion,deletion,find== o(1)   wow ! per ek perticular order maintain nahi karta hi store karne per no.....!
    // bakki saab mamla same hi as simple MAP
    //Qury wale me baut kaam me aata hi



    //++++++++++++++++++++++++++++++++++++++++++++  [SETS]   ++++++++++++++++++++++++++++++++++++++++++
    cout<<"__________________________________________sets_____________________________________"<<endl;


    // maps me se value wala part hata do
    set<string>ss;
    ss.insert("harendra");
    ss.insert("rahul");                           //*** ((insertion))  Tc log(N);
    ss.insert("sandeep");


    auto ittt=ss.find("rahul");                  //*** ((find))       Tc log(N);
    if(ittt==ss.end()){
        cout<<"nahi mila  hi"<<endl;
    }
    else{
        ss.erase(ittt);                         
        cout<<"mil gaya hi"<<endl;
    }
    for(auto val:ss){
        cout<<val<<endl;
    }



    //++++++++++++++++++++++++++++++++++++++++  [UNORDERD_sets]   ++++++++++++++++++++++++++++++++++++++++++
    cout<<"______________________________________UNORDERD_SETS_____________________________________"<<endl;


    // Hash table se impliment hote hi ye guys
    // basic datatype ko lee sakte hi complex datatype ko key me nahi lee sakte hi kiyo ki unke hash value define nahi hote hi islea
    // Tc insertion,deletion,find== o(1)   wow ! per ek perticular order maintain nahi karta hi store karne per no.....!
    // bakki saab mamla same hi as simple SETS
    //Qury wale me baut kaam me aata hi





    //++++++++++++++++++++++++++++++++++++++++  [multiset,multimaps]   ++++++++++++++++++++++++++++++++++++++++++
    cout<<"______________________________________multiset,multimaps_____________________________________"<<endl;


    //MULTIMAPS SETS,MAPS ME BAS 
    // duplicats key bhii store kar sakte hiii
    ////*** ((erase))       TC log(N)       agar ek value delete karne ho to bauhut easy ho jata hi
    //PRARIOTY QUES --->>> MULTISET KA USE KAR SAKTE HI
return 0;
}
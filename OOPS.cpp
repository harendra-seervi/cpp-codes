//***********************************SENDING STUDENT NAME ,AGE AND GENDER****************************

// #include<bits/stdc++.h>
// using namespace std;
// class student{
//     public:
//     string name;
//     int age ;
//     bool gender;
//     void printinfo(){
//         cout << name << endl;
//         cout << age << endl;           //har ek perticular object ki information print kar rahe hi
//         cout << gender << endl;
//     }
// };
// int main() {
//     student arr[2];           //There are two objects in student class
//     for(int i=0;i<2;i++){
//         cin>>arr[i].name;
//         cin>>arr[i].age;      //Har ek object ka name,age,gender input
//         cin>>arr[i].gender;
//     }

//     for(int i=0;i<2;i++){
//         arr[i].printinfo();
//     }
// return 0;
// }

//**********************************constructor and default************************************

#include <bits/stdc++.h>
using namespace std;
class student
{
    string name;
    int age;
    bool gender;

public:
//------------------Default constructor----------------
    student()
    {
        cout << "Default constructor" << endl;
    } 
//-------------------parameterised constructor-----------
    student(string s, int a, bool b)
    {
        cout << "parameterised constructor" << endl;
        name = s;
        age = a;
        gender = b;
    } 
//--------------------Copy constructor-------------------
    student(student &a)
    {
        cout << "Copy constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    } 
//-----------------distructor`-----------------------------
    ~student(){
        cout<<"Distructor is called"<<endl;
    }

//---------------operator-------------------------------
    bool operator ==(student &a){
        if(name==a.name &&age==a.age && gender==a.gender){
            return true;
        }
        return false;
    }


    void printinfo()
    {
        cout << name << endl;
        cout << age << endl; //har ek perticular object ki information print kar rahe hi
        cout << gender << endl;
    }
};


int main()
{
    student a("Harendra", 20, 0);
    student b;
    student c=a;
    a.printinfo();

    if(c==b){
        cout<<"The objects are same"<<endl;
    }
    else{
        cout<<"The objects are not same"<<endl;
    }
    return 0;
}

//***************************************function overloading*************************************************** 

// #include<iostream>

// using namespace std;
// class apnacolege{
//     public:
//     void fun(){
//         cout<<"This is a void function"<<endl;
//     }
//     void fun(int x){
//         cout<<"This is  a in function"<<endl;
//     }
//     void fun(double c){
//         cout<<"This is a double function"<<endl;
//     }
// };
// int main(){
//     apnacolege a;
//     a.fun();
//     a.fun(2);
//     a.fun(2.3);
//     return 0;
// }


//***************************************************operator overloading*******************************************
#include<iostream>

using namespace std;
class complex{

    private:
    int real;
    int imag;
    public:
    complex operator + (complex &obj){
        complex res(4,5);
        res.real=real+obj.real;
        res.imag=imag+obj.imag;
        return res;
    } 
    complex(int x,int y){
        real=x;
        imag=y;
    }
    void print(){
        cout<<real<<" ";    
        cout<<"i"<<imag<<endl;
    }
};
int main(){
    complex a(1,2);
    complex b(4,3);

    complex v=a+b;
    v.print();
    return 0;
}

//************************************************* virtual overloading *****************************************
// #include<iostream>
// using namespace std;

// class base{
//      public:
//     virtual void print (){
//         cout<<"This is a base print"<<endl;
//     }
//     virtual void display(){
//         cout<<"This is a base display "<<endl;
//     }
// };
// class derived:public base {
//     public:
//     void print (){
//         cout<<"This is a derivide print"<<endl;
//     }
//     void display(){
//         cout<<"This is a derived display"<<endl;
//     }
// };

// int main(){
//     base *ptr;
//     derived obj;
//     ptr=&obj;
//     ptr->print();
//     ptr->display();

//     return 0;
// }
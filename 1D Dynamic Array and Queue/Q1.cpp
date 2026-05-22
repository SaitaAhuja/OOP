#include<iostream>
using namespace std;
template<typename T1, typename T2>
class Calculator{
    private:
       T1 num1;
       T2 num2;
    public:
     Calculator(T1 a,T2 b){
       num1=a;
       num2=b;
   }
    void add(){
       cout<<"Addition: "<<(num1+num2)<<endl;
   }
    void subtract(){
      cout<<"Subtraction: "<<(num1-num2)<<endl;
   }
    void multiply(){
     cout<<"Multiplication: "<<(num1*num2)<<endl;
   }
    void divide(){
     if(num2!=0)
      cout<<"Division: "<<(num1/num2)<<endl;
      else
      cout<<"Error: Division by zero"<<endl;
   }
};
  int main(){
   cout<<"\nSame Datatype"<<endl;
   Calculator<int,int> obj1(10,5);
   obj1.add();
   obj1.subtract();
   obj1.multiply();
   obj1.divide();

   cout<<"\nDifferent Datatypes"<<endl;
   Calculator<int,double> obj2(10,2.5);
   obj2.add();
   obj2.subtract();
   obj2.multiply();
   obj2.divide();
  return 0;
}


































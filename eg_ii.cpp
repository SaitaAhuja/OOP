#include<iostream>
using namespace std;
class Complex{
private:
float real;
float imag;
public:
Complex() : real(0), imag(0) {}
void input(){
cout<<"Enter real and imaginary parts respectively"<<endl;
cin>>real;
cin>>imag;
}
Complex operator+(const Complex& obj){
Complex temp;
temp.real=real+obj.real;
temp.imag=imag+obj.imag;
return temp;
}
float getReal(){return real;}
float getImag(){return imag;}
};
int main(){
Complex c1,c2,result;
c1.input();
c2.input();
result=c1+c2;
cout<<"Sum of the two complex numbers: "<<result.getReal()<<" + "<<result.getImag()<<"i"<<endl;
return 0;}









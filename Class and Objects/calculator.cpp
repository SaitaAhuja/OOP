#include<iostream>
using namespace std;
class Calculator{
private:
    double Num1,Num2,Num3;
public:
    Calculator(){
        cout<<"Enter three numbers: ";
        cin>>Num1>>Num2>>Num3;
    }
    double add(double a,double b){
	return a+b;
	}
    double add(double a,double b,double c){
	return a+b+c;
	}
    double multiply(double a,double b){
	return a*b;
	}
    double multiply(double a,double b,double c){
	return a*b*c;
	}
    double subtract(double a,double b){
	return a-b;
	}
    double subtract(double a,double b,double c){
	return a-b-c;
	}
    double divide(double a,double b){
	if(b==0){
	cout<<"Error: Division by zero!"<<endl;
	return 0;
	}
	else{
	return a/b;
	}
  }
    double divide(double a,double b,double c){
    if(b==0||c==0){
	cout<<"Error: Division by zero!"<<endl; 
	return 0;
	}
    else{
	return a/b/c;
    }
    }
    double getNum1(){
	return Num1;
	}
    double getNum2(){
	return Num2;
	}
    double getNum3(){
	return Num3;
	}
};
int main(){ 
Calculator calc;
cout<<"Addition(first two numbers):"<<calc.add(calc.getNum1(),calc.getNum2())<<endl;
cout<<"Addition(all three numbers):"<<calc.add(calc.getNum1(),calc.getNum2(),calc.getNum3())<<endl;
cout<<"Multiplication(first two numbers):"<<calc.multiply(calc.getNum1(),calc.getNum2())<<endl;
cout<<"Multiplication(all three numbers):"<<calc.multiply(calc.getNum1(),calc.getNum2(),calc.getNum3())<<endl;
cout<<"Subtraction(first two numbers):"<<calc.subtract(calc.getNum1(),calc.getNum2())<<endl;
cout<<"Subtraction(all three numbers):"<<calc.subtract(calc.getNum1(),calc.getNum2(),calc.getNum3())<<endl;
cout<<"Division(first two numbers):"<<calc.divide(calc.getNum1(),calc.getNum2())<<endl;
cout<<"Division(all three numbers):"<<calc.divide(calc.getNum1(),calc.getNum2(),calc.getNum3())<<endl;
    return 0;
}





















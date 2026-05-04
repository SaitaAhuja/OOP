#include<iostream>
using namespace std;
class complex{
	int real,imag;
	public:
		complex(int r=0,int i=0){
			real = r;
			imag = i;
		}
		void display();
		friend complex add(complex ob1,complex ob2); //global func memb nhi hai
		friend complex operator+(complex ob1,complex ob2); //global operator overloading 
};
void complex :: display(){
	cout<<real<<imag<<endl;
}
complex add(complex ob1,complex ob2){
	return complex(ob1.real+ob2.real,ob1.imag+ob2.imag);
}
complex operator+(complex ob1,complex ob2){
	return complex(ob1.real+ob2.real,ob1.imag+ob2.imag);
}
int main(){
	complex c1(2,3);
	complex c2(2,3);
	complex c3;
	c3=add(c1,c2); //wot .
	c3.display();// with . bcz member func
	complex c4;
	c4 = c3+c1;
	c4.display();
	return 0;
}

#include<iostream>
using namespace std;
class Calculator{
	private:
		float a;
		float b;
	public:
	Calculator(){
		a = 0;
		b = 0;
		cout<<"Calculator ON!";
	}
	void input(){
		cout<<"Enter 1st Number:"<<endl;
		cin>>a;
		cout<<"Enter 2nd Number:"<<endl;
		cin>>b;	
	}
	void add(){
	 float	sum = a+b;
		cout<<"Sum is "<<sum<<endl;
	}
	void subtract(){
	 float 	sub = a-b;
		cout<<"Subtraction is "<<sub<<endl;
	}
	void multiply(){
	float 	mul = a*b;
		cout<<"Multiplication is "<<mul<<endl;
	}
	void div(){
		if(b!=0){
		float div = a/b;
		cout<<"Division is "<<div<<endl;
	}
	else{
		cout<<"Invalid!";
	}
	}
	void modulus(){
		int c,d;
		cout<<"Enter numbers"<<endl;
		cin>>c>>d;
	  if(d!=0){
	  int mod= c%d;
		cout<<"Modulus is "<<mod<<endl;
	}
	else{
		cout<<"Invalid!"<<endl;
	}
	}
	void square(){
		int e;
		cout<<"Enter number"<<endl;
		cin>>e;
	 float 	sq=e*e;
		cout<<"Square is "<<sq<<endl;
	}
		~Calculator(){
		cout<<"Calculator OFF!";
	}
};
int main(){
	Calculator c1;
	int choice = -1;
	while(choice!=0){
	cout<<"Enter 1 for addition"<<endl;
		cout<<"Enter 2 for sub"<<endl;
			cout<<"Enter 3 for mult"<<endl;
				cout<<"Enter 4 for div"<<endl;
					cout<<"Enter 5 for mod"<<endl;
						cout<<"Enter 6 for square"<<endl;
						cout<<"Enter 0 to exit"<<endl;
  cin>>choice;

 if(choice==1){
 	c1.input();
 	c1.add();
 }
 else if(choice==2){
 	c1.input();
 	c1.subtract();
 }
  else if(choice==3){ 
    c1.input();
 	c1.multiply();
 }
  else if(choice==4){
  	c1.input();
 	c1.div();
 }
  else if(choice==5){
 	c1.modulus();
 }
 else if(choice ==6){
 	c1.square();
 }
 else if(choice == 0){
   cout<<"Thankyou for using!"<<endl; 	
 }
 else {
 	cout<<"Invalid!";
 }
}
							
}

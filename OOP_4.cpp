#include<iostream>
#include<cmath>
using namespace std;
class vector{
private:
float x;
float y;
public:
vector(float a, float b){
	x = a;
	y = b;
}	
vector add(vector &other){
	float a,b;
	a = x + other.x;
	b = y + other.y;
	return vector(a,b);
}
vector subtract(vector &other){
	float a,b;
	a = x - other.x;
	b = y - other.y;
	return vector(a,b);
}
vector multiply(vector &other){
	float a,b;
	a = x*other.x;
	b = y*other.y;
	return vector(a,b);
}
float magnitude(){
	return sqrt(x*x+y*y);
}
void display(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}
};
int main(){
	vector v1(3,4);
	vector v2(1,2);
	
	vector Add = v1.add(v2);
	Add.display();
	vector Subtract = v1.subtract(v2);
	Subtract.display();
	vector Mul = v1.multiply(v2);
	Mul.display();
	float Mag = v1.magnitude();
	Mag.display();
	
	return 0;
}

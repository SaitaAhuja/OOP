#include<iostream>
using namespace std;
class Vector{
private:
double x,y;
public:
Vector(double a=0,double b=0){x=a;y=b;}
Vector operator+(const Vector& v){
Vector temp;
temp.x=x+v.x;
temp.y=y+v.y;
return temp;
}
Vector operator-(const Vector& v){
Vector temp;
temp.x=x-v.x;
temp.y=y-v.y;
return temp;
}
void display(){cout<<"("<<x<<","<<y<<")"<<endl;}
};
int main(){
double x1,y1,x2,y2;
cout<<"Enter x1,y1,x2,y2:"<<endl;
cin>>x1>>y1>>x2>>y2;
Vector v1(x1,y1),v2(x2,y2);
Vector vAdd=v1+v2;
Vector vSub=v1-v2;
vAdd.display();
vSub.display();
return 0;
}



















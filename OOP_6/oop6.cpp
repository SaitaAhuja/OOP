#include<iostream>
using namespace std;
class Shape{
protected:
    int numberOfSides;
    double area;
public:
    Shape(int sides,double a){
        numberOfSides=sides;
        area=a;
    }
    int getNumberOfSides(){
        return numberOfSides;
    }
    double getArea(){
        return area;
    }
    void setArea(double a){
        area=a;
    }
};
class Rectangle:public Shape{
protected:
    double length;
    double width;
public:
    Rectangle(double l,double w,int sides,double a): Shape(sides,a)
    {
        length=l;
        width=w;
    }
    void generateArea(){
        area=length*width;
    }
};

class Circle:public Shape{
private:
    double radius;
public:
    Circle(double r,int sides,double a)
        : Shape(sides,a)
    {
        radius=r;
    }
    void generateArea(){
        area=3.142*radius*radius;
    }
};

class Triangle:public Shape{
private:
    double height;
    double base;
public:
    Triangle(double h,double b,int sides,double a): Shape(sides,a)
    {
        height=h;
        base=b;
    }
    void generateArea(){
        area=(height*base)/2;
    }
};

class Square:public Rectangle{
public:
    Square(double side,int sides,double a): Rectangle(side,side,sides,a){}
    void checkSides(){
        if(length==width)
            cout<<"Both sides are equal"<<endl;
        else
            cout<<"Sides are not equal"<<endl;;
    }
    void generateArea(){
        area=length*width;
    }
};

int main(){
      double l,w,r,h,b,s;

    cout<<"Enter Rectangle length and width: ";
    cin>>l>>w;
    Rectangle rect(l,w,4,0);
    rect.generateArea();
    cout<<"Rectangle Area: "<<rect.getArea()<<endl;

    cout<<"Enter Circle radius: ";
    cin>>r;
    Circle cir(r,1,0);
    cir.generateArea();
    cout<<"Circle Area: "<<cir.getArea()<<endl;

    cout<<"Enter Triangle height and base: ";
    cin>>h>>b;
    Triangle tri(h,b,3,0);
    tri.generateArea();
    cout<<"Triangle Area: "<<tri.getArea()<<endl;

    cout<<"Enter Square side: ";
    cin>>s;
    Square sq(s,4,0);
    sq.checkSides();
    sq.generateArea();
    cout<<"Square Area: "<<sq.getArea()<<endl;

    return 0;
}


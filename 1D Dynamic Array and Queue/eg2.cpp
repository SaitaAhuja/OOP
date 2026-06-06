#include <iostream>
using namespace std;
class A{
public:
    int a;
};
class B : virtual public A{ // adding the virtual keyword
public:
    int b;
};
class C : virtual public A{ // adding the virtual keyword
public:
    int c;
};
class D : public B, public C{
public:
    int d;
};
int main(){
    D obj;
    obj.a = 200; // will no longer cause an error
    cout << obj.a;
}








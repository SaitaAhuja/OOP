#include<iostream>
using namespace std;

class Car;   // forward declaration

class Engine {
private:
   int horsepower;
   int cc;

public:
   Engine() {
       horsepower = 150;
       cc = 2000;
   }

   // Car is friend of Engine
   friend class Car;
};

class Car {
private:
   string name;

public:
   Car() {
       name = "Honda Civic";
   }

   void display(Engine e) {
       cout << "Car Name: " << name << endl;
       cout << "Engine HP: " << e.horsepower << endl;
       cout << "Engine CC: " << e.cc << endl;
   }
};
int main() {
   Engine e;
   Car c;
  c.display(e);
  return 0;
}

   c.display(e);
}

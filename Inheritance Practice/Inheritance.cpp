#include <iostream>
using namespace std;

// 1. Single & Hierarchical Base
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

// 1. Single (Animal -> Dog)
class Dog : public Animal {
public:
    void bark() { cout << "Barking..." << endl; }
};

// 3. Multilevel (Animal -> Dog -> Puppy)
class Puppy : public Dog {
public:
    void weep() { cout << "Weeping..." << endl; }
};

// 4. Hierarchical (Animal -> Cat)
class Cat : public Animal {
public:
    void meow() { cout << "Meowing..." << endl; }
};

// 2. Multiple (Father + Mother -> Child)
class Father {
public:
    void strength() { cout << "High Strength" << endl; }
};

class Mother {
public:
    void patience() { cout << "High Patience" << endl; }
};

class Child : public Father, public Mother {
public:
    void play() { cout << "Playing..." << endl; }
};

// 5. Hybrid (Virtual to solve Diamond Problem)
class A { public: int val = 10; };
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    cout << "Multilevel & Single " << endl;
    Puppy myPuppy;
    myPuppy.eat(); 
    myPuppy.bark();
    myPuppy.weep();

    cout << "Multiple" << endl;
    Child myChild;
    myChild.strength();
    myChild.patience();

    cout << "Hybrid (Diamond)" << endl;
    D obj;
    cout << "Value from top parent: " << obj.val << endl;

    return 0;
}

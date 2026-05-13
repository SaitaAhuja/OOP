#include<iostream>
using namespace std;
class Character {
private:
    string name;
    int level;
    float health;
public:
    Character(string n, int l, float h) : name(n), level(l), health(h) {}
    void display() {
        cout<<"Name: "<<name<<"\nLevel: "<<level<<"\nHealth: "<<health<<endl;
    }
};
class Warrior : virtual public Character {
private:
    float strength;
    string meleeprof;
public:
    Warrior(string n, int l, float h, float s, string m) 
        : Character(n, l, h), strength(s), meleeprof(m) {}
    float getstrength() { return strength; }
    string getmelee() { return meleeprof; }
    void slash() {
	 cout<<"Character used slash!"<<endl;
	  }
    void displayWarrior() {
        display();
        cout<<"Strength: "<<strength<<"\nMelee Prof: "<<meleeprof<<endl;
    }
};
class Mage : virtual public Character {
private:
    int intelligence;
    string spellCastingProf;
public:
    Mage(string n, int l, float h, int intel, string prof) 
        : Character(n, l, h), intelligence(intel), spellCastingProf(prof) {}
    int getintelligence() { return intelligence; }
    string getmagicprof() { return spellCastingProf; }
    void fireball() { 
	cout << "Character cast a Fireball!" << endl; 
	}
    void displayMage() {
        display();
        cout<<"Intelligence: "<<intelligence<<"\nMagic Prof: "<<spellCastingProf<<endl;
    }
};
class Archer : public Character {
private:
    int dexterity;
    string rangedProf;
public:
    Archer(string n, int l, float h, int dex, string rProf) 
        : Character(n, l, h), dexterity(dex), rangedProf(rProf) {}
    void rapidShot() {
        cout<<"Character used Rapid Shot! (Arrows fired in quick succession)"<<endl;
    }
    void displayArcher() {
        display();
        cout<<"Dexterity: "<<dexterity<<"\nRanged Weapons Prof: "<<rangedProf<<endl;
    }
};
class NPC:public Character {
    private:
       string movementPattern;
       string scriptedDialogue;
    public:
       NPC(string n, int l, float h, string move, string talk) 
        :Character(n, l, h), movementPattern(move), scriptedDialogue(talk) {}
    void move() {
        cout<<"NPC is moving in a "<<movementPattern<<" pattern."<<endl;
    }
    void speak() {
        cout << "NPC says: \"" << scriptedDialogue << "\"" << endl;
    }
    void displayNPC() {
        display();
        cout<<"Movement Behavior: "<<movementPattern<<"\nDialogue: "<<scriptedDialogue<<endl;
    }
};
class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, float h, float s, string m, int intel, string prof)
        : Character(n, l, h), Warrior(n, l, h, s, m), Mage(n, l, h, intel, prof) {}
    void displayMighty() {
        cout<<" Mighty Character Stats "<<endl;
        display(); 
        cout<<"Warrior Strength: "<<getstrength()<<endl;
        cout<<"Mage Intelligence: "<<getintelligence()<<endl;
    }
    void useAbilities() {
        slash();
        fireball();
    }
};
int main() {
    cout<<"Testing RPG Character System"<<endl;

    Warrior w1("Kratos", 15, 200.0, 95.5, "Expert");
    cout << "--- Warrior Details ---" << endl;
    w1.displayWarrior();
    w1.slash();
    cout << endl;

    Archer a1("Legolas", 12, 150.0, 90, "Master");
    cout<<"Archer Details"<<endl;
    a1.displayArcher();
    a1.rapidShot();
    cout<<endl;

    NPC n1("Villager", 1, 50.0, "Patrol", "Welcome to Karachi!");
    cout<<"NPC Details"<<endl;
    n1.displayNPC();
    n1.speak();
    cout<<endl;

    Mighty m1("Saita", 50, 500.0, 99.9, "Godly", 100, "Ancient Magic");
    cout<<"Mighty Hero Details"<<endl;
    m1.displayMighty();
    m1.useAbilities();
    return 0;
}


























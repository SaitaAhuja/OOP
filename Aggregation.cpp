//AGGREGATION- whole part relation (has - a), weak form , "part of wholw relationship"

// has ownership, teacher and dep
// dep bnta hai teacher se , dep me hotey hai techers, dept own krha techer ko,dept form horha techer se,part hai teacher dep ka,
//unidirectional relationship, cant be bidircetional like asscocition CAN, ek owner h ek part h (own hone wala)
//dep k part bngege teachers dep is own krne wala, techer is part of dep own horhe hain techer
//techer me dept nhi , dept me teacher h
//but techer ek hi dep ka part ho not necessary can be of multiple, ek se zyada owner hosktey han, bcz tecger dep nhi krha on dep
//lifetime of obj of teacher doent dep on lifteime of obj of dep// dep nhi raha toh techer raheg auska existnce hain
//e.g  : 2 person living on same address, adress has its existnce obj alag se, person ka obj bana nhi bana abhi tk adress ka hai
// ghr toh logo se phele bhi tha naa, ab 2 person k obj ..
// address hai rahul ya rahul has addres?? obv rahul has adress, 
// dep class k andr tecaher class ka ptr obj and obj point to techer
//adress *p inside dm of person bcz person has address
//person obj destroy toh bhi adress not destroyed

// dept techer me dep k andr ptr jo techer ko point krta

//part owner class me cretr nhi hota baar cretr hota pr owner class mem koi ptr hoga jo ya ref variable jo refer ktyga and use kryga and woh prt aur bhi wner hosktey

//MISS :
/* car has a engine ; owner car, part = engine, car class me engine ka dm, both obj independlty,

//CHAT:
Aggregation is a weak “has-a” relationship where one class contains a reference to another class, but both objects can exist independently.
has-a but not owns
/*/


//
//#include<iostream>
//using namespace std;
//
//class Engine{
//public:
//    void start(){
//        cout << "Engine started" << endl;
//    }
//};
//
//class Car{
//private:
//    Engine *eng;   // aggregation (has-a)
//
//public:
//    Car(Engine *e){
//        eng = e;
//    }
//
//    void startCar(){
//        eng->start();
//        cout << "Car started" << endl;
//    }
//};
//
//int main(){
//    Engine e1;     // independent object
//    Car c1(&e1);   // car uses engine
//
//    c1.startCar();
//
//    return 0;
//}

//BY REFERNCE
#include<iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started" << endl;
    }
};

class Car {
private:
    Engine &eng;   // reference (aggregation)

public:
    Car(Engine &e) : eng(e) {   // initializer list ضرور ی ہے (musttttttestttttttttt, cant in body)
        // eng = e; یہاں نہیں لکھ سکتے
    }

    void startCar() {
        eng.start();            // -> کی بجائے .  (dot)
        cout << "Car started" << endl;
    }
};

int main() {
    Engine e1;
    Car c1(e1);    // & نہیں لگاتے یہاں

    c1.startCar();

    return 0;
}





#include<iostream>
#include<vector>
using namespace std;
class Teacher{
	private:
		string name;
	public:
		Teacher(string n){
			name = n;
		}
		string getname(){
			return name;
		}
		~Teacher(){
			
		}
};
class Department{
	private:
		string name;
		vector<Teacher*> list; //aggregation ptr based
	public:
		Department(string n){
			name = n;
		}
		void addteacher(Teacher *t){
			list.push_back(t);
		}
		void removeteacher(Teacher *t){
			for(auto it=list.begin();it!=list.end();it++){
			     if(*it == t) {
				  list.erase(it);
                  break;   //milgayaa to loopend no need again
            }
        }
    }
		void display(){
			for(int i=0;i<list.size();i++){
				cout<<"Name: "<<list[i]->getname()<<endl;
			}
		}
//		void display(){
//		for(Teacher* t : list){
//        cout << t->getname();
//      }
//    }
		~Department(){
			
		}		
};
int main(){
	Department d1("Maths");
	
	Teacher t1("saita");
	Teacher t2("Nain");
	Teacher t3("Angel");
	
	d1.addteacher(&t1);
	d1.addteacher(&t2);
	d1.addteacher(&t3);
	d1.removeteacher(&t2);
	d1.display();
	
	return 0;
	
}



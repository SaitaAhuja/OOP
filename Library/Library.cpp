#include<iostream>
#include<string>
#include<vector>
using namespace std;
class book{
	private:
    	const int id;
		string author;
		string title;
		float price;
		static int count;
	public:
		book(int i,string t,string a, float p):id(i){
			author = a;
			title = t;
			price = p;
			count++;
		}
		int getid() const{
			return id;
		}
		string getauthor(){
			return author;
		}
		string gettitle(){
			return title;
		}
		float getprice(){
			return price;
		}
		void setprice(float pri){
			if(pri>0){
			price = pri;
	      }
		}
		static noofbooks(){
			return count;
		}
};
int book::count=0;
class member{
	private:
		int memid;
		string name;
		static const int maxbooksallowed=5;
		static int count;
	public:
		int borrowedbooks;
		member(int id,string n){
			memid = id;
			name = n;
			borrowedbooks = 0;
			count ++;
		}
		int getid(){
			return memid;
		}
		string getname(){
			return name;
		}
		static getnoofmembers(){ 
			return count;
		} 
		int getborrowedbooks(){
			return borrowedbooks;
		}
		static const getmaxbook(){
			return maxbooksallowed;
		}
};
int member::count=0;
class library{
	private:
	vector<book*>listofbooks;
	vector<member*>listofmembers;
	public:
		void addbooks(book* b){
			listofbooks.push_back(b);
		}
		void registermember(member* m){
			listofmembers.push_back(m);
		}
		void IssueBook(member* m, int id){
			bool found=false;
			for(book* b:listofbooks){
				if(b->getid()==id){
					found = true;
					
				if(m->getborrowedbooks() < m->getmaxbook()){
					m->borrowedbooks++;
					cout<<"Book "<<b->gettitle()<<" borrowed by "<<m->getname()<<endl;
				}
				else{
					cout<<"Unable to borrow books!"<<endl;
				}
				break;	
				}
			} 
			if(!found){
				cout<<"Book not found!"<<endl;
			}
		} 
    void displaybooks(){
    	for(book* b : listofbooks){
    		cout<<"Book ID: "<<b->getid()<<endl;
			cout<<"Book Title: "<<b->gettitle()<<endl;
			cout<<"Book Author: "<<b->getauthor()<<endl;
			cout<<"Book Price: "<<b->getprice()<<endl;
		}
	}
	void DisplayMembers(){
		for(member* m : listofmembers){
			cout<<"Member ID: "<<m->getid()<<endl;
			cout<<"Member Name: "<<m->getname()<<endl;
		}
	}

};
int main(){ 
	library lib;

    book b1(101, "C++ Basics", "Bjarne Stroustrup", 500);
    book b2(102, "Python Programming", "Guido van Rossum", 400);
    book b3(103, "Data Structures", "Mark Allen Weiss", 600);

    lib.addbooks(&b1);
    lib.addbooks(&b2);
    lib.addbooks(&b3);

    member m1 (1, "Alice");
    member m2 (2, "Bob");

    lib.registermember(&m1);
    lib.registermember(&m2);

    cout<<"\nBOOKS\n"<<endl;
    lib.displaybooks();
    cout<<"\nMEMBERS\n"<<endl;
    lib.DisplayMembers();

    cout<<"\nISSUING BOOKS\n"<<endl;
    lib.IssueBook(&m1, 101); 
    lib.IssueBook(&m1, 102); 
    lib.IssueBook(&m1, 103); 
    lib.IssueBook(&m1, 104); 
    lib.IssueBook(&m1, 101); 
    lib.IssueBook(&m1, 102); 
    lib.IssueBook(&m1, 103); 
    lib.IssueBook(&m2, 101);

    cout<<"\nCURRENT BORROWED BOOKS\n"<<endl;
    cout<<m1.getname()<<" borrowed "<<m1.getborrowedbooks()<<" books."<<endl;
    cout<<m2.getname()<<" borrowed "<<m2.getborrowedbooks()<<" books."<<endl;

    return 0;
}

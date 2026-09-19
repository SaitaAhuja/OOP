#include<iostream>
using namespace std;
class Node{
	private:
		int data;
		Node* next;
	public:
		Node(int value){
			data = value;
			next = NULL;
		}
		int getdata(){
			return data;
		}
		Node* getnext(){
			return next;
		}
		void setdata(int value){
			data = value;
		}
		void setnext(Node* newnext){
			next = newnext;
		}
}; 
class LinkedList{
	private:
     Node* head;
    public:
     LinkedList(){
     	head = NULL;
	 }
	 void append(int value){
	    Node* newnode = new Node(value);
		if(head==NULL){
			head = newnode;
			return;
		}
	    Node* temp = head;
	    while(temp->getnext()!=NULL){
	    	temp = temp->getnext();
		}			
		temp->setnext(newnode);
	 }
	  void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout<<temp->getdata() << " ";
            temp = temp->getnext();
        }
        cout<<endl;
    }
void merge(LinkedList& one, LinkedList& two){
    Node* a = one.head;
    Node* b = two.head;

    if(a == NULL){ head = b; return; }
    if(b == NULL){ head = a; return; }

    if(a->getdata() <= b->getdata()){
        head = a;
        a = a->getnext();
    }
    else{
        head = b;
        b = b->getnext();
    }

    Node* tail = head;
    while(a != NULL && b != NULL){
        if(a->getdata() <= b->getdata()){
            tail->setnext(a);
            a = a->getnext();
        }
        else{
            tail->setnext(b);
            b = b->getnext();
        }
        tail = tail->getnext();
    }

    if(a != NULL) tail->setnext(a);
    else          tail->setnext(b);

    one.head = NULL;   
    two.head = NULL;
}
    };

int main() {
    LinkedList list1, list2, merged;
    int n, m, value;

    cout << "Number of elements in 1st list?: ";
    cin >> n;
    cout << "Write Elements (in sorted order): ";
    for(int i = 0; i < n; i++){
        cin >> value;
        list1.append(value);
    }
    
    cout << "Number of elements in 2st list?: ";
    cin >> m;
    cout << "Write Elements (in sorted order):";
    for(int i = 0; i < m; i++){
        cin >> value;
        list2.append(value);
    }
    merged.merge(list1, list2);
    cout << "Merged list: ";
    merged.display();
    
    return 0;
}

//QUEUE
//PRINCIPLE: FIFO
//
//?? FIFO = First In, First Out
//
//Matlab:
//Jo element pehle insert hota hai
//Woh pehle remove hota hai
//REAL LIFE EXAMPLE
//????? Queue in bank / ticket line:
//Jo banda pehle line me aata hai
//Uska kaam pehle hota hai
//Queue me 2 ends hotay hain:
//
//?? Front
//
//?? jahan se deletion hota hai (remove)
//
//?? Rear (back)
//
//?? jahan se insertion hota hai (add)
//
//?? IMPORTANT RULE
//
//?? Insert always at REAR
//?? Remove always from FRONT
//
//?? OPERATIONS (THEORY)
//1. Enqueue (Insertion)
//
//?? element ko queue ke rear end par add karna
//
//2. Dequeue (Deletion)
//
//?? element ko queue ke front se remove karna
//
//3. Front / Peek
//
//?? front element ko dekhna (remove nahi karna)
//
//4. IsEmpty
//
//?? check karna queue empty hai ya nahi
//
//5. IsFull (array implementation)
//
//?? check karna queue full hai ya nahi

#include<iostream>
using namespace std;
class Queue{
	private:
		int *arr;
		int capacity;
		int front;
		int rear;
		
		void resize(){
			int newcap = capacity*2;
			capacity = newcap;
			int *newarr = new int[capacity];
			for(int i=0;i<rear;i++){
				newarr[i]=arr[i];
			}
			delete[] arr;
			arr=newarr;
		}
		
	public:
		Queue(){
			capacity=5;
			arr=new int[capacity];
			front=0;
			rear=0;
		}
		Queue(int c){
			capacity=c;
			arr=new int[capacity];
			front=0;
			rear=0;
		}
		Queue(const Queue &obj){
			front = obj.front;
			rear = obj.rear;
			capacity = obj.capacity;
			arr = new int[capacity];
			for(int i=0;i<rear;i++){
				arr[i]=obj.arr[i];
			}
		}
		Queue& operator=(const Queue& obj){
            if(this == &obj) return *this;
            int* newarr = new int[obj.capacity];
            for(int i = obj.front; i < obj.rear; i++)
               newarr[i] = obj.arr[i];
           delete[] arr;
           arr      = newarr;
          front    = obj.front;
          rear     = obj.rear;
          capacity = obj.capacity;
          return *this;
       }
		bool isfull() const{
			return rear==capacity;
		}
		bool isempty() const{
			return rear==front;
		}
		void enqueue(int value){
			if(isfull()){
				resize();
			}
			arr[rear]=value;
			rear++;
		}
		void dequeue(){
			if(isempty()){
				cout<<"Khali h"<<endl;
				return;
			}
			for(int i=0;i<rear-1;i++){
				arr[i]=arr[i+1];
			}
			rear--;
		}
		int fro() const{
		   if(isempty()){
		   		cout<<"Khali h"<<endl;
				exit(1);
		   }
			return arr[front];
		}
		int rea() const{
			 if(isempty()){
		   		cout<<"Khali h"<<endl;
				return -1;
		   }
			return arr[rear-1];
		}
		void display(){
			for(int i=0;i<rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		~Queue(){
			delete[] arr;
		}
};
int main(){
    Queue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    cout << "Queue: ";
    q1.display();

    cout << "Front: " << q1.fro() << endl;
    cout << "Rear: " << q1.rea() << endl;

    q1.dequeue();

    cout << "After Dequeue: ";
    q1.display();

    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70); // resize bhi test hojayega

    cout << "After More Enqueue: ";
    q1.display();

    cout << "Front: " << q1.fro() << endl;
    cout << "Rear: " << q1.rea() << endl;

    return 0;
}
//STACK:
/*Top=end
LIFO = Last In, First Out
Jo element last me insert hota hai
Woh sab se pehle remove hota hai
Socho ek plate ki stack:
Tum plates ek ek karke upar rakhte ho
Jab uthani hoti hai, tum sab se upar wali plate pehle uthate ho
Neeche wali plate tab tak nahi nikalti jab tak upar wali remove na ho jaye
Stack sirf ek side se operate hota hai:
Top = sirf yahi se insert aur delete hota hai, restricted to tp
So operations always happen at:
push ? top pe add karna
pop ? top se remove karna
Main operations (conceptual)
1. Push
?? element ko stack ke top par add karna
2. Pop
?? top wala element remove karna
3. Peek / Top
?? top element ko dekhna (remove nahi karna)
4. IsEmpty
?? check karna stack empty hai ya nahi
5. IsFull (array implementation me)
check karna space full hai ya nahi
*/
#include<iostream>
using namespace std;
class Stack{
	private:
		int *arr;
		int size;
		int capacity;
		
		void resize(){
			int newcap = capacity*2;
			capacity = newcap;
			int *newarr = new int[capacity];
			for(int i=0;i<size;i++){
				newarr[i]=arr[i];
			}
			delete[] arr;
			arr = newarr;
		}
	public:
		Stack(){
			size = 0;
			capacity = 5; //stack should NEVER start with 0 capacity if push allowed
			arr = new int[capacity];
		}
		Stack(int c){
			size = 0;
			capacity = c;
			arr = new int[capacity];
//			for(int i=0;i<size;i++){
//				arr[i]=0;
//			}
		}
		Stack(const Stack &obj){
			size = obj.size;
			capacity = obj.capacity;
			arr = new int[capacity];
			for(int i=0;i<size;i++){
				arr[i]=obj.arr[i];
			}  //no deletion abhi to bana h
		}
		bool isfull() const{
			return size == capacity;
		}
		bool isempty() const{
			return size == 0;
		}
		void push(int value){
			if(isfull()){
                resize();
           }
            arr[size] = value;
            size++;
		}
		void pop(){
		    if(!isempty()){
                size--;
            }
		}
		int peek() const{
			if(isempty()){
				cout<<"Empty hai"<<endl; //can remove
				return -1;
			}
			else{
				return arr[size-1];
			}
		}
		void display() const{
			for(int i=0;i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		~Stack(){
			delete[] arr;
		}
};
int main(){
	Stack s1(7);
	s1.push(2);
	s1.push(4);
	s1.push(6);
	s1.push(8);
	s1.push(10);
	s1.push(12);
	s1.push(14);
	s1.push(16);
	
	s1.display();
	
	cout<<s1.peek()<<endl;
	
	s1.pop();
	
	s1.display();
	
	
	return 0;
}
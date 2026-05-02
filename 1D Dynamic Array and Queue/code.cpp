#include<iostream>
using namespace std;

template<typename T>
class dynamic_array{
	protected:
	    T* arr;
	    int capacity;
	    int currentsize;
	public:
		dynamic_array(int cap){	
		capacity = cap;
		currentsize=0;
		arr=new T[capacity];
		}
		
	virtual bool isFull()=0;
    virtual bool isEmpty()=0;
    virtual int size()=0;
    virtual void resize()=0;

    virtual ~dynamic_array(){
        delete[] arr;
    }
};
template<typename T>
class Queue : public dynamic_array<T>{
private:
    int front;
    int rear;

public:
    Queue(int cap) : dynamic_array<T>(cap){
        front=0;
        rear=-1;
    }

    bool isFull(){
        return this->currentsize==this->capacity;
    }

    bool isEmpty(){
        return this->currentsize==0;
    }

    int size(){
        return this->currentsize;
    }

    T Front(){
        if(!isEmpty()){
            return this->arr[front];
        }
        else{
            cout<<"Queue is empty"<<endl;
            return T();
    }
   }

    T Rear(){
        if(!isEmpty()){
            return this->arr[rear];
        }
        else{
            cout<<"Queue is empty"<<endl;
            return T();
        }
    }

    void enqueue(T value){
        if(isFull()){
            resize();
        }
        rear++;
        this->arr[rear]=value;
        this->currentsize++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
        this->currentsize--;
    }

    void resize(){
        int newCapacity=this->capacity*2;
        T *newArr=new T[newCapacity];

        for(int i=front, j=0; i<=rear; i++, j++){
            newArr[j]=this->arr[i];
        }

        delete[] this->arr;
        this->arr=newArr;

        rear=this->currentsize-1;
        front=0;
        this->capacity=newCapacity;
    }
    void display(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
   else{
    cout<<"Queue elements: ";
    for(int i=front; i<=rear; i++){
        cout<<this->arr[i]<<" ";
    }
    cout<<endl;
    }
}
};

int main(){
    Queue<int> q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();

    cout<<"Front: "<<q.Front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    cout<<"Size: "<<q.size()<<endl;

    q.enqueue(40); 
    

    cout<<"\nAfter enqueue 40 (after resize):"<<endl;
     q.display();
    cout<<"Front: "<<q.Front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    cout<<"Size: "<<q.size()<<endl;

    q.dequeue();
    cout<<"\nAfter dequeue:"<<endl;
    q.display();
    cout<<"Front: "<<q.Front()<<endl;
    cout<<"Rear: "<<q.Rear()<<endl;
    cout<<"Size: "<<q.size()<<endl;

    return 0;
}

		
		
	

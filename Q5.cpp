#include<iostream>
using namespace std;

template<typename T>
class Queue{
private:
    T* arr;
    int capacity;
    int front;
    int rear;
    int currentSize;
public:
    Queue(int cap){
        capacity = cap;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    bool isEmpty(){
        return currentSize == 0;
    }

    bool isFull(){
        return currentSize == capacity;
    }

    int size(){
        return currentSize;
    }
    void enqueue(T value){
        if(isFull()){
            cout<<"Queue Overflow: Cannot add more print jobs"<<endl;
            return;
        }
        rear++;
        arr[rear] = value;
        currentSize++;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow: No job to remove"<<endl;
            return;
        }
        cout<<"Completed: "<<arr[front]<<endl;
        front++;
        currentSize--;

        if(currentSize == 0){
            front = 0;
            rear = -1;
        }
    }
    T Front(){
        if(!isEmpty())
            return arr[front];
        else{
            cout<<"Queue is empty"<<endl;
            return T();
        }
    }
    T Rear(){
        if(!isEmpty())
            return arr[rear];
        else{
            cout<<"Queue is empty"<<endl;
            return T();
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"No print jobs in queue"<<endl;
            return;
        }
        cout<<"Current Print Queue: ";
        for(int i = front; i <= rear; i++){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    ~Queue(){
        delete[] arr;
    }
};
int main(){
    Queue<string> printer(5);

    printer.enqueue("Client1_File.pdf");
    printer.enqueue("Client2_Image.png");
    printer.enqueue("Client3_Report.docx");
    printer.enqueue("Client4_Poster.jpg");

    cout<<"PRINT JOBS ARRIVED"<<endl;
    printer.display();

    cout<<"\nPRINTING STARTED"<<endl;

    while(!printer.isEmpty()){
        cout<<"\nNow Printing: "<<printer.Front()<<endl;
        printer.dequeue();

        if(!printer.isEmpty()){
            cout<<"Next job ready in queue..."<<endl;
        }
    }
    cout<<"\nAll print jobs completed. Printer is now idle."<<endl;
    return 0;
}












































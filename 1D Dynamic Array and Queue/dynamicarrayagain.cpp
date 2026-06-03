#include<iostream>
using namespace std;
class Dynamicarray{
	private:
		int* arr;
		int capacity;
		int size;
		
		void resize(){
			capacity*=2;
			int *newarr= new int[capacity];
			if(newarr==NULL){
				exit(1);
			}
			for(int i=0;i<size;i++){
				newarr[i]= arr[i];
			}
			delete[] arr;
			arr = newarr;
		}
	public:
		Dynamicarray(){
			capacity = 5;
			arr = new int[capacity];
			size = 0;
		}
		Dynamicarray(int cap){
			capacity = cap;
			size = 0;
			arr = new int[capacity];
		}
		Dynamicarray(const Dynamicarray& other){
			capacity = other.capacity;
			size = other.size;
			arr = new int[capacity];
			for(int i=0;i<size;i++){
				arr[i]=other.arr[i];
			}
		}
		Dynamicarray& operator =(const Dynamicarray& other){
			if(this==&other){
				return *this;
			}
			delete[] arr;
			capacity = other.capacity;
			size = other.size;
			arr = new int[capacity];
			for(int i=0;i<size;i++){
				arr[i]=other.arr[i];
		}
		return *this;
	}
		int getcapacity(){
		return capacity;
	}
	int getsize(){
		return size;
	}
	bool full(){
		return(size==capacity);
	}
	bool empty(){
		return size==0;
	}
	void push(int v){
		if(full()){
			resize();
    	}
		arr[size]=v;
		size ++;
	}
	void pop(){
		if(!empty()){
			size--;
		}
	}
	int& operator[](int index){
		if(index<0||index>=size){
			cout<<"Sharam kro"<<endl;
			exit(1);
		}
		return arr[index];
	}
	void display(){
		cout<<"[";
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"]";
	}
	int front(){
		if(!empty()){
			return *arr;
		}
		return -1;
	}
	int back(){
		if(!empty()){
			return arr[size-1];
		}
		exit(1);
	}
	void insert(int v,int ind){
		if(ind<0||ind>=size){
			cout<<"Sharam"<<endl;
			return;
		}
		if(full()){
			resize();
		}
		for(int i=size;i>=ind;i--){
			arr[i]=arr[i-1];
		}
		arr[ind]=v;
		size++;
	}
	void erase(int ind){
		if(ind<0||ind >= size){
		cout<<"Invalid"<<endl;
		return;
	}
	if(empty()){
		cout<<"Empty"<<endl;
		return;
	}
		for(int i=ind;i<size-1;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
		void clear(){
			size = 0;
		}
		int search(int v){
			if(empty()){
				cout<<"Empty"<<endl;
				exit(1);
			}
			for(int i=0;i<size;i++){
				if(arr[i]==v){
					return i;
				}
			}	
			 return -1;
		}
		   void sort(){
   	for(int i=0;i<size-1;i++){
   		for(int j =0;j<size - i-1;j++){
   			if(arr[j]>arr[j+1]){
   				   int temp = arr[j];
				   arr[j]=arr[j+1];
				   arr[j+1]=temp;
			   }
		   }
	   }
   }
    bool operator==(const Dynamicarray &obj){
    if(size != obj.size) return false;
    for(int i = 0; i < size; i++){
        if(arr[i] != obj.arr[i])
            return false;
    }
    return true;
}
//operator+ ka kaam — do arrays ko merge karna!
 Dynamicarray operator+(const Dynamicarray &obj){
 	Dynamicarray result(size+obj.size);
 	for(int i = 0;i<size;i++){
 		 result.push(arr[i]);
	 }
	for(int i = 0;i<obj.size;i++){
 		 result.push(obj.arr[i]);
	 }
	  return  result;
 }
 
 void reverse(){
    int left = 0;
    int right = size - 1;
    while(left < right){
        // swap
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
};
int main(){
	
}
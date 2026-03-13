#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;
class Dynamic_Array{
	private:
		int *ptr;
		int currentsize;
		int totalsize;
		void resize(){
			totalsize = (totalsize == 0)? 1 : 2*totalsize;
				int *temp = new int[totalsize];
				if(temp == NULL){
					exit(1);
				}
				for(int i=0;i<currentsize;i++){
					temp[i]=ptr[i];
				}
				delete[] ptr;
				ptr = temp;
		}
	public:
		Dynamic_Array(int t=0){
		totalsize = t;
		currentsize = 0;
		ptr = (totalsize>0)? new int[totalsize]: NULL;
		}
		Dynamic_Array(const Dynamic_Array &obj){
			totalsize = obj.totalsize;
			currentsize= obj.currentsize;
			if(totalsize>0){
				ptr =  new int[totalsize];
				for(int i=0;i< currentsize;i++){
					ptr[i] = obj.ptr[i];
				}
		      }
				else{
					ptr = NULL;
				}
			}
		  bool full(){
		  	return totalsize == currentsize;
		  }
		  bool empty(){
		  	return currentsize == 0;
		  }
		  int size(){
		  	return currentsize;
		  }
		  void push(int v){
		  	if(full()){
		  		resize();
		  		ptr[currentsize] = v;
				currentsize++;
			  }
			else{
				ptr[currentsize] = v;
				currentsize++;
			}
		  }
	      void pop(){
	       if(!empty()){
	       	currentsize--;
	       	ptr[currentsize]=0;
		   }
		  }
		  int& operator[] (int index){ //when actual is modified and not the copy sent
		  	if(index < 0 || index >= currentsize){
		  		cout<<"Error"<<endl;
		  		exit(1);
			  }
			  return ptr[index];
		  }
		  Dynamic_Array& operator=(const Dynamic_Array& obj){ //obj is source and this is destination
		  	if(this==&obj)
		  		return *this;
			
			delete[] ptr;
			  
			  currentsize = obj.currentsize;
			  totalsize = obj.totalsize;
			  ptr = new int[totalsize];
			  
			  for(int i = 0; i<currentsize;i++){
			  	  ptr[i] = obj.ptr[i];
			  }
			  return *this;
		  }
		  void display(){
		  	cout<<"[";
		  	for(int i =0;i< currentsize;i++){
		  		cout<<ptr[i]<<" ";
			  }
			cout<<"]"<<endl;
		  }
		  int capacity(){
		  	return totalsize;
		  }
		  void clear(){
		  	currentsize = 0;  
		  }
		  int back(){
		  	if(empty()){
		  		cout<<"empty array"<<endl; 
		  		exit(1);
			  }
		  	return ptr[currentsize - 1]; //ptr[i] is equivalent to *(ptr + i) in C++.
		  }
		  int front(){
		  	if(empty()){
		  		cout<<"empty array"<<endl; 
		  		exit(1);
			  }
		  	return *ptr; //ptr[0] is equivalent to *ptr 
		  }
		  void insert(int index, int value){
		  	if(full()){
		  		resize();
			  }
			if(index < 0 || index > currentsize){
				cout<<"OUT OF BOUNDS"<<endl;
			}
			for(int i=currentsize;i>index;i--){
             ptr[i] = ptr[i-1];
             }

		  	ptr[index]=value;
			   currentsize++;	
		  }
		  ~Dynamic_Array(){
		  delete [] ptr;
		  }		
		  void erase(int index){
		  		if(index < 0 || index > currentsize){
				cout<<"OUT OF BOUNDS"<<endl;
			}
			for(int i=index;i<currentsize-1;i++){
        ptr[i] = ptr[i+1];
    }

    currentsize--;
}
int search(int value){

    for(int i=0;i<currentsize;i++){
        if(ptr[i] == value)
            return i;
    }

    return -1;
}
};
int main(){
	Dynamic_Array D1(3);
	D1.push(1);
	D1.display();
	D1.push(2);
	D1.display();
	D1.push(3);
	D1.display();
	D1.pop();
	D1.display();
	D1.push(4);
	D1.display();
	Dynamic_Array D2 = D1;
	D2.display();
	Dynamic_Array D3;
	D3 = D2;
	D3.display();
	Dynamic_Array D4(D3);
	D4.display();
	cout<<D4[0]<<endl;
	D4.insert(0,6);
	D4.display();
	return 0;
}

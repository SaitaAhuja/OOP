#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	int *array = new int[n];
	int *ptr = array;
	for(int i = 0; i < n ;i ++){
		cin>>*(ptr+i);
	}
	for(int i = 0; i < n ;i ++){
		cout<<*(ptr+i);
	}
	int big = *ptr;
	for(int i = 0;i<n;i++){
		if(*(ptr+i)>big){
			big = *(ptr+i);
		}
}
cout<<big<<endl;
delete[] array;
return 0;
}




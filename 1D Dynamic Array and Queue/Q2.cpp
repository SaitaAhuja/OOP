#include<iostream>
using namespace std;

template<typename T1, typename T2>
void swapData(T1 &a, T2 &b){
    auto temp=a;
    a=b;
    b=temp;
}

int main(){
    int x=10, y=20;
    cout<<"Before swap (int): "<<x<<" "<<y<<endl;
    swapData(x,y);
    cout<<"After swap (int): "<<x<<" "<<y<<endl;

    double p=5.5;
    int q=2;
    
	cout<<"\nSwapping different data types may cause implicit conversion and data loss and it is unavoidable"<<endl;
    cout<<"Before swap (mixed): "<<p<<" "<<q<<endl;
    swapData(p,q);
    cout<<"After swap (mixed): "<<p<<" "<<q<<endl;

    return 0;
}

































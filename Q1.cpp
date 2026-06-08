#include <iostream>
using namespace std;
class Base {
private:
    int privateInt;      

protected:
    int protectedInt;    

public:
    int publicInt;     

    void setPrivateInt(int x){ privateInt = x; }
    void setProtectedInt(int x){ protectedInt = x; }
    void setPublicInt(int x){ publicInt = x; }

    int getPrivateInt(){ return privateInt; }
    int getProtectedInt(){ return protectedInt; }
    int getPublicInt(){ return publicInt; }
};
class publicChild : public Base {
public:
    // Public function to access protected member from main
    int accessProtected(){ 
	return protectedInt; }
};
class protectedChild : protected Base {
public:
    void setAll(int a,int b,int c){
        setPrivateInt(a);
        protectedInt = b;
        publicInt = c;
    }

    int getPrivate(){ return getPrivateInt(); }
    int getProtected(){ return protectedInt; }
    int getPublic(){ return publicInt; }
};
class privateChild : private Base {
public:
    void setAll(int a,int b,int c){
        setPrivateInt(a);
        protectedInt = b;
        publicInt = c;
    }

    int getPrivate(){ return getPrivateInt(); }
    int getProtected(){ return protectedInt; }
    int getPublic(){ return publicInt; }
};

int main(){

    cout<<"========== Public Inheritance =========="<<endl;
    publicChild pc;
    pc.setPrivateInt(10);
    pc.setProtectedInt(20);
    pc.publicInt = 30;

    cout<<"privateInt:"<<pc.getPrivateInt()<<endl;
	cout<<"(Accessed private through base getter)"<<endl;
    cout<<"protectedInt:"<<pc.accessProtected()<<endl;
	cout<<"(Accessed protected through child public function)"<<endl;
    cout<<"publicInt:"<<pc.publicInt<<"(Accessed public directly)"<<endl;

    cout<<"\n========== Protected Inheritance =========="<<endl;
    protectedChild prc;
    prc.setAll(40,50,60);

    cout<<"privateInt:"<<prc.getPrivate()<<endl;
	cout<<"(Accessed private through base getter via child public function)"<<endl;
    cout<<"protectedInt:"<<prc.getProtected()<<endl;
	cout<<"(Accessed protected via child public function)"<<endl;
    cout<<"publicInt:"<<prc.getPublic()<<endl;
	cout<<"(Accessed public via child public function because it became protected)"<<endl;

    cout<<"\n========== Private Inheritance =========="<<endl;
    privateChild pvc;
    pvc.setAll(70,80,90);

    cout<<"privateInt:"<<pvc.getPrivate()<<endl;
	cout<<"(Accessed private through getter because private not inherited directly)"<<endl;
    cout<<"protectedInt:"<<pvc.getProtected()<<endl;
	cout<<"(Accessed protected via child public function because it became private)"<<endl;
    cout<<"publicInt:"<<pvc.getPublic()<<endl;
	cout<<"(Accessed public via child public function because it became private)"<<endl;

    return 0;
}












#include<iostream>
using namespace std;
class complex{
	private:
		float real;
		float imag;
	public:
		complex(){
			real = 0;
			imag = 0;
		}
		complex(float r, float i){
			real = r;
			imag = i;
		}
		complex(const complex &c){
			real = c.real;
			imag = c.imag;
		}
		complex operator+(const complex &c)const{
			complex temp;
			temp.real = real+c.real;  // actual change nhi krna 2 lekr alag se add kna isliya start me no &
			temp.imag = imag+c.imag;
			return temp;
		}
		complex operator-(const complex &c)const{
			return complex(real-c.real, imag - c.imag);
		}
		complex operator*(const complex &c)const{
			complex temp;
			temp.real = real*c.real  - imag*c.imag;
			temp.imag = real*c.imag + imag*c.real;
			return temp;
		}
		complex operator /(const complex &c) const{   
			complex temp;
			temp.real = (real*c.real  + imag*c.imag)/(c.real*c.real+c.imag*c.imag);
			temp.imag = (imag*c.real  - real*c.imag)/(c.real*c.real+c.imag*c.imag);
			return temp;
		}
////		complex operator-(){  // need a copy boss wohi mt update kro
////			return complex(-real,-imag);
////		}
//	complex operator -() {   
//			complex temp;
//			temp.real = -(this->real);
//			temp.imag = -(this->imag);
//			return temp;
//		}
    	complex operator -() {   
			complex temp;              
			temp.real = -(real);
			temp.imag = -( imag);   // this and above two are exactly samee...
			return temp;
		}
		complex& operator ++(){  //Bغیر & ke ek extra copy banti hai, & se same object return hoga directly.
			++real;
			++imag;
			return *this;
		}
		complex operator ++(int){
			return complex(real++,imag++);
		}
		bool operator==(const complex &c)const{
			return (real == c.real&&imag == c.imag);
		}
		bool operator!=(const complex &c) const{
			return (real != c.real || imag != c.imag); //  ||ayga , && and , nhi
		}
//		bool operator<(const complex &c)const{  //return (real < c.real, imag < c.imag);Ye comma operator hai, && nahi!Comma operator kya karta hai:Pehli condition evaluate karta hai — real < c.real ✅Phir ignore kar deta hai ❌ doosri condition return karta hai — imag < c.imag
//			return (real<c.real&&imag<c.imag);
//		}
		bool operator<(const complex &c) const{  
		   complex temp;             // compring magnitude
		   return(real*real + imag*imag<c.real*c.real + c.imag*c.imag);
    	}
//    	bool operator>(const complex &c)const{  
//			return (real>c.real&&imag>c.imag);
//		}
    	bool operator>(const complex &c) const{  
		               // compring magnitude
		   return(real*real + imag*imag>c.real*c.real + c.imag*c.imag);
    	}
    	friend std::ostream& operator<<(std::ostream &out, const complex &c) {
            out << c.real << " + " << c.imag << "i";  
            return out;                               
        }
		friend std::istream& operator>>(std::istream &in, complex &c) {
            in >> c.real >> c.imag; 
            return in;              
        }
        // member function — c + 5
        complex operator+(int x) const{
            return complex(real + x, imag);  // c.operator+(5) // c.operator+(5)   // c khud call kar raha hai c left side pe hai — to wo khud call karta hai ✅
       }
        // friend function — 5 + c
        friend complex operator+(int x, const complex &c){
             return complex(x + c.real, c.imag);  // operator+(5, c)
      }
        //Friend function class ke bahar hota hai, koi bhi call kar sakta hai:
        //cppoperator+(5, c)   // koi object call nahi kar raha
        //Compiler dhundta hai — koi aisa function jo (int, complex) le sake — friend mil jata hai ✅
        complex& operator--(){
        	--real;
        	--imag;
        	return *this;
		}
		complex operator--(int){
			return complex(real--,imag--);
		}
		bool operator>=(const complex &c)const{
			return(real*real + imag*imag >= c.real*c.real + c.imag*c.imag);
		}
		bool operator<=(const complex &c)const{
			return(real*real + imag*imag <= c.real*c.real + c.imag*c.imag);
		}
        complex& operator+=(const complex &c){
			real += c.real;  
			imag += c.imag;
			return *this;
		}
//Soch ke dekho — += ka matlab kya hai?
//cppcomplex a(3, 4);
//complex b(1, 2);
//a += b;
//Iska matlab hai:
//cppa = a + b;  // a khud update hoga!
        complex& operator-=(const complex &c){
			real -= c.real;  
			imag -= c.imag;
			return *this;
		}
        complex& operator*=(const complex &c){
		float newreal = real*c.real - imag*c.imag;  //real badalgaya.//nextline me new real xxxx
        float newimag = real*c.imag + imag*c.real;
        real = newreal;
        imag = newimag;
			return *this;
		}
		complex& operator/=(const complex &c){
		float newreal = (real*c.real  + imag*c.imag)/(c.real*c.real+c.imag*c.imag);
		float newimag = (imag*c.real  - real*c.imag)/(c.real*c.real+c.imag*c.imag);
		 real = newreal;
        imag = newimag;
		return *this;
		}
		complex& operator = (const complex &c){
			real=c.real;
			imag = c.imag;
			return *this; 
		}
		complex operator !()const{
			return complex(real,-(imag));
		}

};
int main(){
	return 0;
}

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
		complex(float r){
			real = r;
			imag = 0;
		}
		complex(float r, float i){
			real = r;
			imag = i;
		}
		complex operator +(const complex &c) const{
		complex temp;
		temp.real = real + c.real;
		temp.imag = imag + c.imag;
		return temp;
		}
		complex operator -(const complex &c) const{
        return complex(real-c.real,imag-c.imag);
		}
		complex operator *(const complex &c) const{   
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
		complex operator -() {   
			complex temp;
			temp.real = -(this->real);
			temp.imag = -(this->imag);
			return temp;
		}
		complex operator ++() {
		   ++this->real;
		   ++this->imag;
		   return *this;
		}
		complex operator ++(int) {
		   complex temp = *this;
		   this->real++;
		   this->imag++;
		   return temp;
		}
		bool operator==(const complex &c) const{  
		    return(real==c.real&&imag==c.imag);
    	}
    	bool operator!=(const complex &c) const{  
		    return(real!=c.real&&imag!=c.imag);
    	}
    	bool operator>(const complex &c) const{  
		   complex temp;
		   temp.real = real*real + imag*imag;
		   temp.imag = c.real*c.real + c.imag*c.imag;
		   return(temp.real>temp.imag);
    	}
    	bool operator<(const complex &c) const{  
		   complex temp;
		   temp.real = real*real + imag*imag;
		   temp.imag = c.real*c.real + c.imag*c.imag;
		   return(temp.real<temp.imag);
    	}
    	friend std::ostream& operator<<(std::ostream &out, const complex &c) {
            out << c.real << " + " << c.imag << "i";  
            return out;                               
}
		friend std::istream& operator>>(std::istream &in, complex &c) {
            in >> c.real >> c.imag; 
            return in;              
}

       complex operator+(int x)  const{
        	return complex(x+this->real,imag);
	   }
	   
    	
};

     	int add(int a,int b){
    		return a+b;
		}
	 	double add(double a,double b){
				return a+b;
		}
     complex add(complex &c1,complex &c2){
        	return c1+c2;
		}

int main() {
    complex c1(3, 4), c2(1, 2), c3;

    // ---------- Arithmetic ----------
    c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    c3 = c1 - c2;
    cout << "c1 - c2 = " << c3 << endl;

    c3 = c1 * c2;
    cout << "c1 * c2 = " << c3 << endl;

    c3 = c1 / c2;
    cout << "c1 / c2 = " << c3 << endl;

    // ---------- Unary minus ----------
    c3 = -c1;
    cout << "-c1 = " << c3 << endl;

    // ---------- Increment ----------
    ++c1;
    cout << "++c1 = " << c1 << endl;

    c1++;
    cout << "c1++ = " << c1 << endl;

    // ---------- Comparisons ----------
    cout << boolalpha; // to print true/false
    cout << "c1 == c2? " << (c1 == c2) << endl;
    cout << "c1 != c2? " << (c1 != c2) << endl;
    cout << "c1 < c2? " << (c1 < c2) << endl;
    cout << "c1 > c2? " << (c1 > c2) << endl;

    // ---------- Input/Output ----------
    cout << "Enter a complex number (real imag): ";
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    // ---------- Function overloading ----------
    cout << "add(5, 10) = " << add(5, 10) << endl;
    cout << "add(3.5, 2.5) = " << add(3.5, 2.5) << endl;
    cout << "add(c1, c2) = " << add(c1, c2) << endl;

    // ---------- Mixed operands ----------
    c3 = c1 + 5;
    cout << "c1 + 5 = " << c3 << endl;


    return 0;
}







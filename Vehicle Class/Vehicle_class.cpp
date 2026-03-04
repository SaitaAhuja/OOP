#include<iostream>
using namespace std;
class vehicle{
    private:
	double maxspeed;
	double speed;
	double fuel;
	int on;
	
	public:
		vehicle(double m){
			maxspeed = m;
			speed = 0;
			fuel = 0;
			on = 0;
		}
		bool addfuel(double amount){
			if(amount>0){
				fuel += amount;
				cout<<"Fuel has been added!"<<endl;
		    return true;
			}
			cout<<"Invalid Amount";
			return false;
		}
		bool start(){
		if(fuel){
		on = 1;
		consumeFuel(1);
		return true;
		}
		return false;
    	}
    	bool accelerate(double s){
    		if(on && fuel >= 1){
    			if(s>0 && (s+speed)<=maxspeed){
    				speed += s;
    				cout<<"Car is accelerated by "<<s<<endl;
    				cout<<"Current Speed of Car is"<<speed<<endl;
    			return true;
				}
			}
			return false;
		}
		bool brake(double b){
			if(on){
				if(b>0 && (speed-b)>=0){
					speed-=b;
					cout<<"Car brake by "<<b<<endl;
    				cout<<"Current Speed of Car is"<<speed<<endl;
    				return true;
				}
			}
			return false;
		}
		bool stop(){
    if(speed == 0){
        on = 0;
        return true;
    }
    return false;
}
void consumeFuel(double amount){
    fuel -= amount;
    if(fuel <= 0){
        fuel = 0;
        on = 0;
        speed = 0;
    }
}


};
int main(){
	vehicle car(1000);
	car.addfuel(300.0);
	car.start();
	car.accelerate(500);
	car.brake(50);
}

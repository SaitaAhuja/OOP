#include<iostream>
using namespace std;
class Vehicle{
private:
	string type;
    string make;
    string model;
    string color;
    int year;
    double milesDriven;
public:
    Vehicle(string t, string mk, string mdl,
            string clr, int y, double miles) {
        type = t;
        make = mk;
        model = mdl;
        color = clr;
        year = y;
        milesDriven = miles;
    }
    string getType() {
        return type;
    }
    string getMake() {
        return make;
    }
    string getModel() {
        return model;
    }
    string getColor() {
        return color;
    }
    int getYear() {
        return year;
    }
    double getMilesDriven() {
        return milesDriven;
    }
    void displayVehicle() {
        cout<<"Type: "<<type<<endl;
        cout<<"Make: "<<make<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Year: "<<year<<endl;
        cout<<"Miles Driven: "<<milesDriven<<endl;
    }
};	
class GasVehicle:virtual public Vehicle{
	private:
	    float FuelTankSize;
	public:
		GasVehicle(string t, string mk, string mdl,string clr, int y, double miles,float tank)
		:Vehicle(t, mk, mdl, clr, y, miles){
            FuelTankSize = tank;
    }
		float getfueltanksize(){
			return FuelTankSize;
		}
};
class ElectricVehicle:virtual public Vehicle{
	private:
	    float EnergyStorage;
	public:
		ElectricVehicle(string t,string mk,string mdl,string clr,int y,double miles,float energy)
        :Vehicle(t,mk,mdl,clr,y,miles), EnergyStorage(energy) {}
		float getenergystorage(){
			return EnergyStorage;
		}
};
class HighPerformance: public GasVehicle{
	private:
		double horsepower;
		double topspeed;
	public:
		HighPerformance(string t,string mk,string mdl,string clr,int y,double miles,float tank,double hp,double ts)
        :Vehicle(t,mk,mdl,clr,y,miles), GasVehicle(t,mk,mdl,clr,y,miles,tank), horsepower(hp), topspeed(ts) {}
		double gethorsepower(){
			return horsepower;
		}
		double gettopspeed(){
			return topspeed;
		}
};
class HeavyVehicle: public GasVehicle, public ElectricVehicle{
	private:
		double maximumweight;
		int wheels;
		double length;
	public:
		HeavyVehicle(string t,string mk,string mdl,string clr,int y,double miles,float tank,float energy,double mw,
		int w,double l):Vehicle(t,mk,mdl,clr,y,miles), GasVehicle(t,mk,mdl,clr,y,miles,tank)
		,ElectricVehicle(t,mk,mdl,clr,y,miles,energy), maximumweight(mw), wheels(w), length(l) {}
		double maxweight(){
			return maximumweight;
		}
		double getlength(){
			return length;
		}
		int getwheels(){
			return wheels;
		}
};
class SportsCar: public HighPerformance{
	private:
		string gearbox;
		string drivesystem;
	public:
	SportsCar(string t,string mk,string mdl,string clr,int y,double miles,float tank,double hp,double ts,string g,string d)
    :Vehicle(t,mk,mdl,clr,y,miles),HighPerformance(t,mk,mdl,clr,y,miles,tank,hp,ts),gearbox(g), drivesystem(d){}
		string getgearbox(){
			return gearbox;
		}
		string getdrivesystem(){
			return drivesystem;
		}
};
class ConstructionTruck: public HeavyVehicle{
	private:
		string cargo;
	public:
		ConstructionTruck(string t,string mk,string mdl,string clr,int y,double miles,float tank,float energy
		,double mw,int w,double l,string c):Vehicle(t,mk,mdl,clr,y,miles), HeavyVehicle(t,mk,mdl,clr,y,miles,tank,energy,mw,w,l),
		cargo(c) {}
		string getcargo(){
			return cargo;
		}
};
class Bus:public HeavyVehicle{
	private:
	   int noofseats;
	public:
		Bus(string t,string mk,string mdl,string clr,int y,double miles,float tank,float energy,double mw,int w,
		double l,int seats):Vehicle(t,mk,mdl,clr,y,miles),HeavyVehicle(t,mk,mdl,clr,y,miles,tank,energy,mw,w,l), 
		noofseats(seats) {}
		int getnoofseats(){
			return noofseats;
		}
		void display(){
        cout<<"Vehicle Class Members"<<endl;
        cout<<"Type:"<<getType()<<endl;
        cout<<"Make:"<<getMake()<<endl;
        cout<<"Model:"<<getModel()<<endl;
        cout<<"Color:"<<getColor()<<endl;
        cout<<"Year:"<<getYear()<<endl;
        cout<<"Miles:"<<getMilesDriven()<<endl;
        
        cout<<"Gas Vehicle Class Members"<<endl;
        cout<<"Tank Size:"<<getfueltanksize()<<endl;
        
        cout<<"Electric Vehicle Class Members"<<endl;
        cout<<"Energy Storage:"<<getenergystorage()<<endl;
        
        cout<<"Heavy Vehicle Class Members"<<endl;
        cout<<"Weight:"<<maxweight()<<endl;
        cout<<"Wheels:"<<getwheels()<<endl;
        cout<<"Length:"<<getlength()<<endl;
        
        cout<<"Bus Class Members"<<endl;
        cout<<"Seats:"<<noofseats<<endl;
    }
};
int main(){
    Bus myBus("Public","Hino","Kazay","White",2024,5000.5,150.0,300.0,15000.0,6,35.5,45);
    myBus.display();
    return 0;
}

#include<iostream>
using namespace std;
class Account{
	protected:
		double balance;
	public:
		Account(double bal){
			balance = bal;
		}
	    void deposit(double amt){
	    	if(amt>0){
	    	balance+=amt;
			}
			else{
				cout<<"Invalid Amount!"<<endl;
			}
	   }
		void withdraw(double amt){
		if(amt>0&&amt<=balance){
	    	balance-=amt;
			}
			else{
				cout<<"Invalid Amount!"<<endl;
			}
     	}
		double checkbalance(){
			return balance;
		}
};
class InterestAccount : virtual public Account { 
    protected:
       double Interest;
    public:
       InterestAccount(double b):Account(b){
       	Interest= 30.0;
	   }
       InterestAccount(double b, double i) : Account(b), Interest(i) {}
        void deposit(double amount) {
        	if(amount>0){
        double interestAmount = amount * (Interest / 100.0);
        balance += (amount + interestAmount);
        cout<<"Deposited with interest. New Balance: "<<balance<<endl;
      }
      	else{
				cout<<"Invalid Amount!"<<endl;
			}
    }
};
class ChargingAccount : virtual public Account {
    protected:
       double fee;
    public:
       ChargingAccount(double b):Account(b){
	       fee=25.0;
	   }
       ChargingAccount(double b, double f) : Account(b), fee(f) {}
       void withdraw(double amount) {
         if ((amount + fee) <= balance) {
            balance -= (amount + fee);
            cout << "Withdrawn with fee. New Balance: " << balance << endl;
         } else {
            cout << "Insufficient balance!" << endl;
         }
     }
};
class ACI:public InterestAccount,public ChargingAccount {
    public:
       ACI():Account(0.0),InterestAccount(0.0,30.0),ChargingAccount(0.0,25.0){}
       ACI(double b,double i,double f):Account(b),InterestAccount(b,i),ChargingAccount(b,f){}
       void transfer(double amount,Account &acc){
         if((amount+fee)<=balance){
             this->withdraw(amount);
             acc.deposit(amount);
             cout<<"Transferred Rs."<<amount<<" to General Account."<<endl;
          }
       }

       void transfer(double amount,InterestAccount &acc){
         if((amount+fee)<=balance){
            this->withdraw(amount);
            acc.deposit(amount);
            cout<<"Transferred Rs."<<amount<<" to Interest Account."<<endl;
         }
     }

        void transfer(double amount,ChargingAccount &acc){
         if((amount+fee)<=balance){
            this->withdraw(amount);
            acc.deposit(amount);
            cout<<"Transferred Rs."<<amount<<" to Charging Account."<<endl;
         }
     }
};

int main(){
    ACI myAci(5000,30,25);
    Account basic(1000);
    InterestAccount saving(1000,30);
    ChargingAccount business(1000,25);

    cout<<"Initial ACI Balance: ";myAci.checkbalance();

    myAci.transfer(500,basic);
    myAci.transfer(500,saving);
    myAci.transfer(500,business);

    cout<<"\nFinal Results "<<endl;
    cout<<"ACI: "<<myAci.checkbalance();
    cout<<"Basic: "<<basic.checkbalance();
    cout<<"Saving: "<<saving.checkbalance();
    cout<<"Business: "<<business.checkbalance();

    return 0;
}



























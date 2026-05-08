#include<iostream>
#include<string>
using namespace std;
class Store {
    protected:
       double total_bill;
    public:
    Store(double bill) {
        total_bill = bill;
    }
    virtual void calculateFinalBill() = 0;
};
class ImtiazStore : public Store {
public:
    ImtiazStore(double bill):Store(bill){};
    void calculateFinalBill() override {
        double discount = total_bill * 0.07; 
        double final_bill = total_bill - discount;
        cout<<"Imtiaz Store"<<endl;
        cout<<"Total Bill: "<<total_bill<<endl;
        cout<<"Discount (7%): "<<discount<<endl;
        cout<< "Final Bill: "<<final_bill<<endl<<endl;
    }
};
class BinHashimStore : public Store {
public:
    BinHashimStore(double bill):Store(bill){};
    void calculateFinalBill() override {
        double discount = total_bill * 0.05; 
        double final_bill = total_bill - discount;
        cout<<"Bin Hashim Store"<<endl;
        cout<<"Total Bill: "<<total_bill<<endl;
        cout<<"Discount (5%): "<<discount<<endl;
        cout<<"Final Bill: "<<final_bill<<endl<<endl;
    }
};
int main() {
    double billAmount;
    cout<<"Enter the total bill amount: ";
    cin>>billAmount;
    Store* storePtr;

    ImtiazStore imtiaz(billAmount);
    storePtr = &imtiaz;
    storePtr->calculateFinalBill();

    BinHashimStore binHashim(billAmount);
    storePtr = &binHashim;
    storePtr->calculateFinalBill();

    return 0;
}




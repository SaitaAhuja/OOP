#include<iostream>
#include<string>
using namespace std;
class encryption{
	protected:
		string msg;
	public:
		encryption(string m){
			msg= m;
		}
	virtual void encrypt()=0;
	virtual void decrypt(int size)=0;
	virtual ~encryption(){
		
	}
};
class technique1: public encryption{
	public:
		technique1(string m):encryption(m){
		}
	void encrypt(){
		string result;
		for(int i=0;i<msg.length();i++){
			result += to_string(int(msg[i]));
		}
		
		cout<<result<<endl;
	}
	
	void decrypt(int size){
	      int code;
        cout << "Enter ASCII values(with spaces)): ";

        for(int i = 0; i < msg.length(); i++){
            cin >> code;
            cout << char(code);
        }
        cout << endl;
        cin.ignore();
    }

};
class technique2: public encryption{
	public:
		technique2(string m):encryption(m){
		}
	void encrypt(){
		string result;
		for(int i=0;i<msg.length();i++){
			result += to_string(int(msg[i]+2));
		}
		
		cout<<result<<endl;
	}
		
	void decrypt(int size){
	  int code;
        cout << "Enter ASCII values: ";

        for(int i = 0; i < msg.length(); i++){
            cin >> code;
            cout << char(code - 2);
        }
        cout << endl;
        cin.ignore();
    }

};
int main(){
	
	encryption* obj;
	string msg;
	cout<<"Enter msg"<<endl;
	getline(cin,msg);
	technique1 tech(msg);
	obj = &tech;
	obj->encrypt();
	obj->decrypt(5);
	technique2 t(msg);
	obj = &t;
	obj->encrypt();
	obj->decrypt(5);   //83 97 105 116 97
	return 0;
}
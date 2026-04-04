#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int n;
	cin>>n;
	int d;
	int a[n];
	long long reward = 0;
	for(int i =0;i<n;i++){
		cin>>a[i]>>d;
		reward += d;
	}
	sort(a,a+n);
	long long time = 0;
	for(int i =0;i<n;i++){
		time+=a[i];
		reward -= time;
		
	}
	cout<<reward<<endl;
	return 0;
}

#include <iostream>

using namespace std;

int main (){
	int n;
	cin >> n;
	if (n<21){
		cout << -1 << endl;
		return 0;
	}
	if (n>=22 && n<=29){
		cout << -1 << endl;
		return 0;
	}
	if (n%14==13 || n%14==0 || n%14==1){
		cout << -1 << endl;
		return 0;
	}
	cout << n/14;
	return 0;
}
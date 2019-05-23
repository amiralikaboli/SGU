#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	if (n==1){
		cout << "1 0";
		return 0;
	}
	if (n==2){
		cout << "2 1" << endl;
		cout << "1 2";
		return 0;
	}
	if (n==3){
		cout << "3 3" << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "1 3" << endl;
		return 0;
	}
	cout << n << " " << 2*n-4 << endl;
	cout << "1 2" << endl;
	cout << "2 3" << endl;
	cout << "3 4" << endl;
	cout << "1 4" << endl;
	for (int i=5;i<=n;++i){
		cout << 1 << " " << i << endl;
		cout << 3 << " " << i << endl;
	}
}
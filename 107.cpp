#include <iostream>

using namespace std;

int main (){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n<9){
		cout << 0;
		return 0;
	}
	if (n==9){
		cout << 8;
		return 0;
	}
	cout << 72;
	for (int i=0;i<n-10;i++)
		cout << '0';
}
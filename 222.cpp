#include <iostream>

using namespace std;

int C(int n,int k){
	if (k>=n || k<1)
		return 1;
	return C(n-1,k)+C(n-1,k-1);
}

int fact(int n){
	if (n<1)
		return 1;
	return fact(n-1)*n;
}

int main (){
	int n,k;
	cin >> n >> k;
	if (k>n){
		cout << 0;
		return 0;
	}
	cout << C(n,k)*C(n,k)*fact(k);
}
#include <iostream>

using namespace std;

int main (){
	long long n;
	cin >> n;
	if (n%3==0){
		cout << (n-1)/2;
		return 0;
	}
	cout << (n+1)/2;
}
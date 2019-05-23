#include <iostream>

using namespace std;

long long p(long long x){
	long long n=x;
	long long cnt=1;
	while (n!=0){
		cnt*=n%10;
		n/=10;
	}
	if (cnt==0)
		return x+1;
	return cnt;
}

int main (){
	int n;
	cin >> n;
	if (n==1){
		cout << 8 << endl;
		return 0;
	}
	if (n%6==1){
		cout << 4 << endl;
		return 0;
	}
	if (n%3==1){
		cout << 3 << endl;
		return 0;
	}
	cout << 1 << endl;
}
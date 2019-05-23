#include <iostream>

using namespace std;

int five[20];

int check(int n){
	int cnt=0;
	for (int i=1;i<15;++i)
		cnt+=n/five[i];
	return cnt;
}

int main (){
	int q;
	cin >> q;
	if (q==0){
		cout << 1 << endl;
		return 0;
	}
	five[1]=5;
	for (int i=2;i<15;++i)
		five[i]=five[i-1]*5;
	for (int i=4*q-((4*q)%5)+100;i>=0;i-=5){
		if (check(i)==q){
			cout << i << endl;
			return 0;
		}
		if (check(i)<q){
			cout << "No Solution" << endl;
			return 0;
		}
	}
}
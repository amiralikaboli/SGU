#include <iostream>
using namespace std;
int a[12];
int main (){
	int n,k,h,sum=0;
	cin >> k >> n;
	for (int i=1;i<=n;++i){
		cin >> h;
		++a[h/1000];
	}
	for (int i=0;i<10;++i){
		a[i]+=k-1;
		sum+=a[i]/k;
	}
	cout << sum+2;
}

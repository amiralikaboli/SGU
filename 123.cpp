#include <iostream>
using namespace std;
int a[50];
int main (){
	int n;
	long long sum=0;
	cin >> n;
	a[1]=1;
	a[2]=1;
	if (n==1)
		sum=1;
	if (n>=2)
		sum=2;
	for (int i=3;i<=n;++i){
		a[i]=a[i-1]+a[i-2];
		sum+=a[i];
	}
	cout << sum;
}

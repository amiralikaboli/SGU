#include <iostream>
using namespace std;
int a[1010];
int n;
int f(int n){
	int sum=0;
	while (n>9){
		while (n!=0){
			sum+=(n%10);
			n/=10;
		}
		n=sum;
		sum=0;
	}
	return n;
}
int fact (int k){
	if (k<=0)
		return a[0];
	return f(fact (k-1))*a[k];
}
void solve () {
	int sum=0,n;
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
		a[i]=f(a[i]);
		sum+=fact (i);
		sum=f(sum);
	}
	cout << sum << endl;
}
int main (){
	int k;
	cin >> k;
	for (int i=1;i<=k;++i)
		solve();
	return 0;
}

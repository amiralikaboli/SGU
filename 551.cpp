#include <iostream>

using namespace std;

int main (){
	long long n,t1,t2;
	cin >> n >> t1 >> t2;
	long long ans=0;
	long long ind=0;
	while(ind/t1+ind/t2<n)
		++ind;
	ans=(ind+t1-1)/t1+(ind+t2-1)/t2;
	cout << ans << " " << max((ind+t1-1)/t1*t1,(ind+t2-1)/t2*t2);
}
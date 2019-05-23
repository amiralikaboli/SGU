#include <iostream>

using namespace std;

int a[111];

int tav(int n,int k){
	int cnt=1;
	if (n==0)
		return 0;
	for (int i=0;i<k;++i)
		cnt*=n;
	return cnt;
}

int main (){
	int n,k,ans=0;
	cin >> n >> k;
	for (int i=0;i<n;++i)
		cin >> a[i];
	if (k%2==0)
		for (int i=0;i<n;++i)
			ans+=tav(a[i],k);
	else
		for (int i=0;i<n;++i)
			if (a[i]>0)
				ans+=tav(a[i],k);
	cout << ans;
}
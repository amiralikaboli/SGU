#include <iostream>

using namespace std;

int a[111][111];

int ghadr(int x){
	return max(x,-x);
}

int main (){
	int n,m;
	cin >> n >> m;
	long long ans=0;
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j){
			char c;
			cin >> c;
			a[i][j]=c-'0';
			if (a[i][j]!=0)
				ans+=2;
		}
	for (int i=0;i<n;++i)
		ans+=a[i][0]+a[i][m-1];
	for (int i=0;i<m;++i)
		ans+=a[0][i]+a[n-1][i];
	for (int i=0;i<n;++i)
		for (int j=0;j<m-1;++j)
			ans+=ghadr(a[i][j]-a[i][j+1]);
	for (int i=0;i<m;++i)
		for (int j=0;j<n-1;++j)
			ans+=ghadr(a[j][i]-a[j+1][i]);
	cout << ans;
}
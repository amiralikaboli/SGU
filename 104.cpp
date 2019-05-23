#include <iostream>
#include <vector>

using namespace std;

const int INF=1000*1000*1000+7;
int a[111][111],dp[111][111];
int par[111][111];
vector <int> v;

int main(){
	int n,k;
	cin >> n >> k;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=k;++j)
			dp[i][j]=-INF;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=k;++j)
			cin >> a[i][j];
	for (int i=1;i<=n;++i){
		dp[i][i]=dp[i-1][i-1]+a[i][i];
		par[i][i]=i-1;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=k;++j)
			for (int x=i;x<j;++x){
				dp[i][j]=max(dp[i][j],dp[i-1][x]+a[i][j]);
				if (dp[i][j]==dp[i-1][x]+a[i][j])
					par[i][j]=x;
			}
	/*for (int i=0;i<=n;++i){
		for (int j=0;j<=k;++j)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	int c;
	int mx=-INF;
	for (int i=n;i<=k;++i)
		if (dp[n][i]>mx){
			c=i;
			mx=dp[n][i];
		}
	v.push_back(c);
	for (int i=n;i>=2;--i){
		v.push_back(par[i][c]);
		c=par[i][c];
	}
	cout << mx << endl;
	for (int i=n-1;i>=0;--i)
		cout << v[i] << " ";
}
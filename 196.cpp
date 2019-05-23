#include <iostream>

using namespace std;

int d[11111];

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for (int i=0;i<m;++i){
		int a,b;
		cin >> a >> b;
		++d[a];
		++d[b];
	}
	int ans=0;
	for (int i=1;i<=n;++i)
		ans+=d[i]*d[i];
	cout << ans;
}
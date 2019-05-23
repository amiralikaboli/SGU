#include <bits/stdc++.h>

using namespace std;

const int MaxN=5E5+10;
int l[MaxN];

int check (int n){
	int ans=0;
	for (int i=0;i<n;++i)
		if (l[i]>0)
			++ans;
	return ans;
}
int main (){
	int n,ans=0;
	cin >> n;
	for (int i=0;i<n;++i)
		cin >> l[i];
	while (check (n)!=1){
		sort (l,l+n);
		int cnt=0;
		while (l[cnt]==0)
			++cnt;
		--l[cnt];
		l[n-1]+=l[n-2];
		l[n-2]=0;
		++ans;
	}
	cout << ans;
}

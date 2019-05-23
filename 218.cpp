#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int MaxN=500+10;
const int MaxAns=1E6+10;
int n;
int a[MaxN][MaxN];
int match[MaxN],mark[MaxN];
pii ans[MaxN];

bool dfs(int x,int w){
	if (x==-1)
		return true;
	for (int i=0;i<n;++i)
		if (a[x][i]<=w && !mark[i]++ && dfs(match[i],w)==true){
			match[i]=x;
			return true;
		}
	return false;
}

bool check(int w){
	fill_n(match,n,-1);
	for (int i=0;i<n;++i){
		fill_n(mark,n,0);
		if (dfs(i,w)==false)
			return false;
	}
	return true;
}

int main(){
	cin >> n;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			cin >> a[i][j];
	int s=-MaxAns,e=MaxAns;
	int w;
	while (e!=s+1){
		w=(s+e)/2;
		if (check(w))
			e=w;
		else
			s=w;
	}
	if (check(e))
		w=e;
	cout << w << endl;
	for (int i=0;i<n;++i)
		ans[i]=pii(match[i]+1,i+1);
	sort(ans,ans+n);
	for (int i=0;i<n;++i)
		cout << ans[i].first << " " << ans[i].second << endl;
}
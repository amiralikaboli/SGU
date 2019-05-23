#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>

const int MaxN=4E5+10;
bool mark[MaxN];
int x[MaxN],y[MaxN];
vector <int> adj[MaxN];
map <int,int> mp_x,mp_y;

pii dfs(int v){
	mark[v]=true;
	pii ans=pii(1,0);
	for (int i=0;i<adj[v].size();++i){
		int u=adj[v][i];
		if (mark[u]==false){
			pii cnt=dfs(u);
			ans.first+=cnt.second;
			ans.second+=cnt.first;
		}
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt=0;
	for (int i=0;i<n;++i){
		cin >> x[i] >> y[i];
		if (mp_x.find(x[i])==mp_x.end())
			mp_x[x[i]]=cnt++;
		if (mp_y.find(y[i])==mp_y.end())
			mp_y[y[i]]=cnt++;
		adj[mp_x[x[i]]].push_back(mp_y[y[i]]);
		adj[mp_y[y[i]]].push_back(mp_x[x[i]]);
	}
	int ans=0;
	for (int i=0;i<cnt;++i)
		if (mark[i]==false){
			pii t=dfs(i);
			ans+=t.first*t.second;
		}
	cout << ans;
}
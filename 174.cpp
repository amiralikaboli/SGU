#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int MaxN=4E5+10;
int par[MaxN],h[MaxN];
map <pii,int> mp;

int find_root(int v){
	if (par[v]==-1)
		return v;
	par[v]=find_root(par[v]);
	return par[v];
}

void smaller_to_bigger(int u,int v){
	int ru=find_root(u);
	int rv=find_root(v);
	if (h[ru]<h[rv])
		par[ru]=rv;
	else if (h[ru]>h[rv])
		par[rv]=ru;
	else{
		par[rv]=ru;
		++h[ru];
	}
}

int main(){
	ios::sync_with_stdio(false);
	fill(h,h+MaxN,1);
	fill(par,par+MaxN,-1);
	int n;
	cin >> n;
	int cnt=0;
	for (int i=0;i<n;++i){
		int x1,x2,y1,y2;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		if (mp.find(pii(x1,y1))==mp.end())
			mp[pii(x1,y1)]=cnt++;
		if (mp.find(pii(x2,y2))==mp.end())
			mp[pii(x2,y2)]=cnt++;
		int v1 = mp[pii(x1,y1)], v2 = mp[pii(x2,y2)];
		if (find_root(v1)==find_root(v2)){
			cout << i+1;
			return 0;
		}
		smaller_to_bigger(v1,v2);
	}
	cout << 0 << endl;
	return 0;
}
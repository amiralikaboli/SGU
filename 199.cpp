#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int MaxN=1E5+10;
const int INF=1E9+123;
int par[MaxN];
pii p[MaxN];
vector <int> bis;
vector <int> ind;
map <pii,int> mp;

bool cmp(pii a,pii b){
	if (a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}

void solve(int t){
	if (par[t]>-1)
		solve(par[t]);
	cout << mp[p[t]] << " ";
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> p[i].first >> p[i].second;
		mp[p[i]]=i+1;
	}
	sort(p,p+n,cmp);
	for (int i=0;i<n;++i){
		int pos=lower_bound(bis.begin(),bis.end(),p[i].second)-bis.begin();
		if (pos==bis.size()){
			bis.push_back(p[i].second);
			ind.push_back(i);
		}
		else{
			bis[pos]=p[i].second;
			ind[pos]=i;
		}
		if (pos==0)
			par[i]=-1;
		else
			par[i]=ind[pos-1];
	}
	cout << bis.size() << endl;
	int last=ind.back();
	solve(last);
}
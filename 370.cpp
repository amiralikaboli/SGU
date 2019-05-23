#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define pi acos(-1)
#define X real()
#define Y imag()
#define point complex<ld>

const int MaxN=1E6+10;
const ld eps=1E-8;
const int INF=1E9+7;
const int MOD=1000*1000*1000+7;
int cnt[MaxN];
vector <int> p[MaxN];

int pow(int n,int k){ if(k==0) return 1; int cnt=pow(n,k/2); if(k%2==0) return (cnt*cnt)%MOD; else return (n*pow(n,k-1))%MOD;}

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	cout << fixed << setprecision(12);
//input
	int n,m;
	cin >> n >> m;
	--n;
	--m;
	if (n==0 && m==0){
		cout << 0;
		return 0;
	}
	if (n==0 || m==0){
		cout << 1;
		return 0;
	}
//gharbal & find differnt prime
	for (int i=2;i<MaxN;++i)
		if (!p[i].size())
			for (int j=i;j<MaxN;j+=i)
				p[j].pb(i);
//update cnt
	for (int i=1;i<=n;++i)
		for (int j=0;j<(1<<p[i].size());++j){
			int x=1;
			for (int l=0;l<p[i].size();++l)
				if (j&(1<<l))
					x*=p[i][l];
			++cnt[x];
		}
//find ans
	long long ans=2;
	for (int i=1;i<=m;++i)
		for (int j=0;j<(1<<p[i].size());++j){
			int x=1;
			int t=0;
			for (int l=0;l<p[i].size();++l)
				if (j&(1<<l)){
					++t;
					x*=p[i][l];
				}
			if (t%2)
				ans-=cnt[x];
			else
				ans+=cnt[x];
		}
//output
	cout << ans;
}
#include <iostream>
#include <vector>

using namespace std;

const int Max=16000+10;
const int INF=1E9;
bool mark[Max];
int dp[Max];
vector <int> v[Max];

void dfs (int vertex){
	mark[vertex]=true;
	for (int i=0;i<v[vertex].size ();++i)
		if (mark[v[vertex][i]]==false){
			dfs(v[vertex][i]);
			if (dp[v[vertex][i]]>0)
				dp[vertex]+=dp[v[vertex][i]];
		}
}

int main (){
	int n;
	cin >> n;
	for (int i=1;i<=n;++i)
		cin >> dp[i];
	for (int i=1;i<n;++i){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs (1);
	int ans=-INF;
	for (int i=1;i<=n;++i)
		ans=max(ans,dp[i]);
	cout << ans;
}
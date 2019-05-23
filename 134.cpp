#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MaxN=16666;
bool mark_dfs[MaxN],mark_bfs[MaxN],mark_dp[MaxN];
int dist[MaxN],dp[MaxN],ans[MaxN];
queue <int> q;
vector <int> centroid;
vector <int> v[MaxN];

void dfs(int src){
	mark_dfs[src]=true;
	for (int i=0;i<v[src].size();++i)
		if (mark_dfs[v[src][i]]==false){
			mark_dfs[v[src][i]]=true;
			dfs(v[src][i]);
		}
	for (int i=0;i<v[src].size();++i)
		if (mark_dp[v[src][i]]==true)
			dp[src]+=dp[v[src][i]];
	mark_dp[src]=true;
}

void bfs(int src){
	mark_bfs[src]=true;
	q.push(src);
	while (!q.empty()){
		src=q.front();
		q.pop();
		for (int i=0;i<v[src].size();++i)
			if (mark_bfs[v[src][i]]==false){
				mark_bfs[v[src][i]]=true;
				dist[v[src][i]]=dist[src]+1;
				q.push(v[src][i]);
			}
	}
}

int main (){
	int n;
	cin >> n;
	for (int i=0;i<n-1;++i){
		int x,y;
		cin >> x >> y;
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	for (int i=0;i<n;++i)
		dp[i]=1;
	dfs(0);
	bfs(0);
	for (int i=0;i<n;++i)
		for (int j=0;j<v[i].size();++j)
			if (dist[i]<dist[v[i][j]])
				ans[i]=max(ans[i],dp[v[i][j]]);
			else
				ans[i]=max(ans[i],n-dp[i]);
	int mn=MaxN;
	for (int i=0;i<n;++i)
		mn=min(mn,ans[i]);
	for (int i=0;i<n;++i)
		if (ans[i]==mn)
			centroid.push_back(i+1);
	sort(centroid.begin(),centroid.end());
	cout << mn << " " << centroid.size() << endl;
	for (int i=0;i<centroid.size();++i)
		cout << centroid[i] << " ";
}
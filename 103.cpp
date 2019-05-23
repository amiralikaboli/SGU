#include<bits/stdc++.h>

using namespace std;

const int MaxN=300+10;
const int INF=1E9;
vector < pair<int,int> > adj[MaxN];
int par[MaxN];
int ct[5][MaxN];
int sc[MaxN];
int st[MaxN];
int dist[MaxN];
set < pair<int,int> > pst;

int findColor(int vtx,int time){
	if (time<st[vtx])
		return sc[vtx];
	int tnf=time-st[vtx];
	tnf%=(ct[0][vtx]+ct[1][vtx]);
	if (tnf<ct[!sc[vtx]][vtx])
		return !sc[vtx];
	else
		return sc[vtx];
}

int findEndPart(int vtx,int time){
	if (time<st[vtx])
		return st[vtx];
	return (time-st[vtx])/(ct[0][vtx]+ct[1][vtx])*(ct[0][vtx]+ct[1][vtx])+st[vtx]+ct[!sc[vtx]][vtx]+(sc[vtx]==findColor(vtx,time) ? ct[sc[vtx]][vtx] : 0);
}

int findDistance(int dad,int child,int time){
	if (sc[dad]!=sc[child] and st[dad]==st[child] and ct[0][dad]==ct[1][child] and ct[1][dad]==ct[0][child])
		return INF;
	if (findColor(dad,time)==findColor(child,time))
		return time;
	if (findEndPart(dad,time)==findEndPart(child,time))
		return min(findEndPart(dad,findEndPart(dad,time)+1),findEndPart(child,findEndPart(child,time)+1));
	return min(findEndPart(dad,time),findEndPart(child,time));
}

void Dijkstra(int root){
	dist[root]=0;
	pst.erase(make_pair(INF,root));
	pst.insert(make_pair(0,root));
	int ind=0;
	while(!pst.empty()){
		set < pair<int,int> >::iterator it=pst.begin();
		int vtx=it->second;
		pst.erase(it);
		for (int i=0;i<adj[vtx].size();++i){
			int u=adj[vtx][i].first;
			int w=adj[vtx][i].second;
			if (dist[u]>findDistance(vtx,u,dist[vtx])+w){
				pst.erase(make_pair(dist[u],u));
				dist[u]=findDistance(vtx,u,dist[vtx])+w;
				pst.insert(make_pair(dist[u],u));
				par[u]=vtx;
			}
		}
	}
}

int main(){
	int src,snc;
	cin >> src >> snc;
	--src; --snc;
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;++i){
		char col;
		cin >> col >> st[i] >> ct[0][i] >> ct[1][i];
		sc[i]=(col=='P');
	}
	for (int i=0;i<m;++i){
		int u,v,w;
		cin >> u >> v >> w;
		--u; --v;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	fill(dist,dist+n,INF);
	fill(par,par+n,-1);
	for (int i=0;i<n;++i)
		pst.insert(make_pair(dist[i],i));
	Dijkstra(src);
	if (dist[snc]>=INF)
		return cout << 0, 0;
	cout << dist[snc] << endl;
	vector <int> v;
	v.push_back(snc+1);
	int dad=par[snc];
	while (dad!=-1){
		v.push_back(dad+1);
		dad=par[dad];
	}
	for (int i=v.size()-1;i>=0;--i)
		cout << v[i] << " ";
	// for (int i=0;i<n;++i)
	// 	cerr << endl << i+1 << " : " << dist[i];
}
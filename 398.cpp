#include <iostream>
#include <vector>

using namespace std;

bool b_x[55],ans[55];
vector <int> v[55];

int main(){
	int n,x;
	cin >> n >> x;
	--x;
	for (int i=0;i<n;++i){
		int t;
		cin >> t;
		for (int j=0;j<t;++j){
			int a;
			cin >> a;
			v[i].push_back(--a);
		}
	}
	b_x[x]=true;
	for (int i=0;i<v[x].size();++i)
		b_x[v[x][i]]=true;
	for (int i=0;i<v[x].size();++i){
		int u=v[x][i];
		for (int j=0;j<v[u].size();++j)
			ans[v[u][j]]=true;
	}
	int r=0;
	for (int i=0;i<n;++i)
		if (ans[i]==true && b_x[i]==false)
			++r;
	cout << r << endl;
	for (int i=0;i<n;++i)
		if (ans[i]==true && b_x[i]==false)
			cout << i+1 << " ";
}
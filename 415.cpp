#include <bits/stdc++.h>

using namespace std;

const int MaxN=200+10;
const int MaxX=1E4+10;
bool dp_s[MaxN][MaxX],dp_e[MaxN][MaxX];
int a[MaxN];
vector <int> ans;

int main(){
	int n,x;
	cin >> n >> x;
	for (int i=0;i<n;++i)
		cin >> a[i];
	if (n==1){
		cout << 1 << "\n" << a[0];
		return 0;
	}
	sort(a,a+n);
	for (int i=0;i<n;++i){
		dp_s[i][a[i]]=true;
		dp_s[i][0]=true;
	}
	for (int i=n-1;i>=0;--i){
		dp_e[i][a[i]]=true;
		dp_e[i][0]=true;
	}
	for (int i=1;i<n;++i)
		for (int j=0;j<=x;++j)
			if (dp_s[i-1][j]==true){
				if (j+a[i]<=x)
					dp_s[i][j+a[i]]=true;
				dp_s[i][j]=true;
			}
	for (int i=n-2;i>=0;--i)
		for (int j=0;j<=x;++j) 
			if (dp_e[i+1][j]==true){
				if (j+a[i]<=x)
					dp_e[i][j+a[i]]=true;
				dp_e[i][j]=true;
			}
	/*for (int i=0;i<n;++i){
		for (int j=0;j<=x;++j)
			cerr << dp_s[i][j] << " ";
		cerr << endl;
	}
	cerr << endl;
	for (int i=0;i<n;++i){
		for (int j=0;j<=x;++j)
			cerr << dp_e[i][j] << " ";
		cerr << endl;
	}*/
	if (dp_s[n-2][x]==false)
		ans.push_back(a[n-1]);
	if (dp_e[1][x]==false)
		ans.push_back(a[0]);
	for (int i=1;i<n-1;++i){
		bool h=false;
		for (int j=0;j<=x;++j)
			if (dp_s[i-1][j]==true && dp_e[i+1][x-j]==true)
				h=true;
		if (h==false)
			ans.push_back(a[i]);
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();++i)
		cout << ans[i] << " ";
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxN=1000*10+10;
bool b[MaxN];
int color[MaxN];
vector <int> v;

void mq(int n){
	v.clear();
	v.push_back(1);
	for (int i=2;i*i<=n;++i)
		if (n%i==0){
			if (i*i==n)
				v.push_back(i);
			else{
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	int x=0;
	for (int i=0;i<v.size();++i)
		x=max(color[v[i]],x);
	for (int i=1;i<=x;++i)
		b[i]=false;
	for (int i=0;i<v.size();++i)
		b[color[v[i]]]=true;
	bool q=false;
	for (int i=1;i<=x;++i)
		if (b[i]==false){
			q=true;
			color[n]=i;
			break;
		}
	if (q==false)
		color[n]=x+1;
}

int main (){
	int n;
	cin >> n;
	int ans=0;
	for (int i=1;i<=n;++i){
		mq(i);
		ans=max(ans,color[i]);
	}
	cout << ans << endl;
	for (int i=1;i<=n;++i)
		cout << color[i] << " ";
}
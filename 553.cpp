#include <bits/stdc++.h>

using namespace std;

const int MaxN=2E5+10;
int SumW[MaxN],SumC[MaxN];

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	for( int i=0;i<n;++i){
		int w,c;
		cin >> w >> c;
		SumW[i]=(i>0 ? SumW[i-1] : 0)+w;
		SumC[i]=(i>0 ? SumC[i-1] : 0)+c;
	}
	int ans=0;
	int h=0,t=0;
	for( int i=n;i>m;--i){
		int cnt=SumW[i-1]-SumW[i-m-1];
		if(k*SumW[i-m-1]<cnt)
			break;
		int ind=-1;
		int s=0,e=i-m-1;
		while (s<=e){
			int mid=(s+e)/2;
			if(k*(SumW[i-m-1]-SumW[mid])>=cnt){
				ind=mid;
				s=mid+1;
			}
			else
				e=mid-1;
		}
		int calc=SumC[n-1]-SumC[i-1]+(ind>=0 ? SumC[ind] : 0);
		if(ans<calc){
			ans=calc;
			t=ind+1;
			h=n-i;
		}
	}
	cout << t+h << " " << ans << endl;
	for( int i=0;i<h;++i)
		cout << 'H';
	for( int i=0;i<t;++i)
		cout << 'T';
}
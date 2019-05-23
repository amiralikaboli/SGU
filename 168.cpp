#include <iostream>
#include <cstdio>

using namespace std;

const int MaxN=1000+10;
const int INF=32*1000+7;

int a[MaxN][MaxN];
int b[MaxN][MaxN];

int f(int i,int j){
	int ans=a[i][j];
	ans=min(ans,b[i][j+1]);
	ans=min(ans,b[i-1][j+1]);
	ans=min(ans,b[i+1][j]);
	return ans;
}

int main(){
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for (int i=0;i<=n+1;++i)
		for (int j=0;j<=m+1;++j)
			b[i][j]=INF;
	for (int j=m;j>=1;--j)
		for (int i=n;i>=1;--i)
			b[i][j]=f(i,j);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}
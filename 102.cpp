#include <iostream>

using namespace std;

int bmm(int x,int y){
	if (x%y==0)
		return y;
	return bmm(y,x%y);
}

int main (){
	int n,cnt=0;
	cin >> n;
	for (int i=1;i<n;++i)
		if (bmm(n,i)==1)
			++cnt;
	cout << cnt;
}
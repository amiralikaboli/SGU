#include <iostream>

using namespace std;

int main (){
	int a,b;
	cin >> a >> b;
	int ind=0;
	while (ind<=35){
		if (a==0 || b==0){
			cout << ind << endl;
			return 0;
		}
		int x=min(a,b);
		int y=max(a,b);
		y-=x;
		x*=2;
		a=x;
		b=y;
		++ind;
	}
	cout << -1 << endl;
}
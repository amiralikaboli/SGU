#include <iostream>

using namespace std;

int main (){
	int s,p;
	cin >> s >> p;
	int t=p-s;
	if (p<=s)
		cout << 0;
	else if (t==0)
		cout << 0;
	else if (t<5*60)
		cout << 1;
	else if (t>=5*60 && t<15*60)
		cout << 2;
	else if (t>=15*60 && t<30*60)
		cout << 3;
	else if (t>=30*60)
		cout << 4;
}
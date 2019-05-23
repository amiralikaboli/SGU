#include <iostream>

using namespace std;

int first[15]={0,1,4,4,7,2,5,7,3,6,1,4,6};
int day[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int d,m;
	cin >> d >> m;
	if (m>12 || d>day[m]){
		cout << "Impossible";
		return 0;
	}
	if ((d+first[m]-1)%7==0)
		cout << 7;
	else
		cout << (d+first[m]-1)%7;
}
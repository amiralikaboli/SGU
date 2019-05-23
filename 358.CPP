#include <iostream>
#include <algorithm>

using namespace std;

int a[10];

int main (){
	for (int i=0;i<9;++i)
		cin >> a[i];
	sort(a,a+3);
	sort(a+3,a+6);
	sort(a+6,a+9);
	a[0]=a[4];
	a[2]=a[7];
	sort(a,a+3);
	cout << a[1] << endl;
}
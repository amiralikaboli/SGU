#include <iostream>

using namespace std;

string s[111];

int main (){
	int n,k;
	cin >> k >> n;
	for (int i=1;i<n;++i)
		cin >> s[i];
	cin >> s[0];
	cout << s[k%n];
}
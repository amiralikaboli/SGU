#include <iostream>

using namespace std;

int secret[10],guess[10];

int main(){
	string s,t;
	cin >> s >> t;
	for (int i=0;i<4;++i){
		s[i]-='0';
		t[i]-='0';
	}
	int bull=0;
	int cow=0;
	for (int i=0;i<4;++i){
		++secret[s[i]];
		++guess[t[i]];
	}
	for (int i=0;i<10;++i)
		cow+=min(secret[i],guess[i]);
	for (int i=0;i<4;++i)
		if (s[i]==t[i]){
			--cow;
			++bull;
		}
	cout << bull << " " << cow;
}
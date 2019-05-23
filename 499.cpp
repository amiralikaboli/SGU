#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MaxN=1E5+10;
const int MaxA=1E6+10;
int t[MaxA];

void process(int x){
	for (int i=1;i*i<x;++i)
		if (x%i==0){
			++t[i];
			++t[x/i];
		}
	int q=sqrt(x);
	if (sqrt(x)==q)
		++t[q];
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n;++i){
		int a;
		cin >> a;
		process(a);
	}
	for (int i=MaxA;i>=1;--i)
		if (t[i]>=2){
			cout << i;
			return 0;
		}
}
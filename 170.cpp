#include <iostream>

using namespace std;

int main(){
	string s,t;
	cin >> s >> t;
	int p_s=0,p_t=0;
	for (int i=0;i<s.size();++i){
		if (s[i]=='+')
			++p_s;
		if (t[i]=='+')
			++p_t;
	}
	if (p_t!=p_s){
		cout << -1;
		return 0;
	}
	int ans=0;
	for (int i=0;i<t.size();++i){
		if (s[i]!=t[i]){
			int ind=i;
			while(t[i]==t[ind] && ind<t.size())
				++ind;
			swap(t[i],t[ind]);
			ans+=ind-i;
		}
	}
	if (s!=t){
		cout << -1;
		return 0;
	}
	cout << ans;
}
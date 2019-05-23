#include <iostream>

using namespace std;

int t[5];

int main (){
	int l,a,b;
	string s;
	cin >> l >> a >> b;
	cin >> s;
	if (a+b>l){
		cout << -1 << endl;
		return 0;
	}
	int ans=0;
	for (int i=0;i<s.size();++i)
		++t[s[i]-'0'];
	if (a==t[0] && b==t[1]){
		cout << 0 << endl << s << endl;
		return 0;
	}
	if (a>t[0] && b>t[1]){
		for (int i=0;i<s.size() && a>t[0];++i)
			if (s[i]=='2'){
				s[i]='0';
				++ans;
				--t[2];
				++t[0];
			}
		for (int i=0;i<s.size() && b>t[1];++i)
			if (s[i]=='2'){
				s[i]='1';
				++ans;
				--t[2];
				++t[1];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a<t[0] && b<t[1]){
		for (int i=0;i<s.size() && a<t[0];++i)
			if (s[i]=='0'){
				s[i]='2';
				++ans;
				--t[0];
				++t[2];
			}
		for (int i=0;i<s.size() && b<t[1];++i)
			if (s[i]=='1'){
				s[i]='2';
				++ans;
				--t[1];
				++t[2];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a==t[0] && b>t[1]){
		for (int i=0;i<s.size() && b>t[1];++i)
			if (s[i]=='2'){
				s[i]='1';
				++ans;
				--t[2];
				++t[1];
			}
		cout << ans << endl << s << endl;
		return 0; 
	}
	if (a==t[0] && b<t[1]){
		for (int i=0;i<s.size() && b<t[1];++i)
			if (s[i]=='1'){
				s[i]='2';
				++ans;
				--t[1];
				++t[2];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a>t[0] && b==t[1]){
		for (int i=0;i<s.size() && a>t[0];++i)
			if (s[i]=='2'){
				s[i]='0';
				++ans;
				--t[2];
				++t[0];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a<t[0] && b==t[1]){
		for (int i=0;i<s.size() && a<t[0];++i)
			if (s[i]=='0'){
				s[i]='2';
				++ans;
				--t[0];
				++t[2];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a<t[0] && b>t[1]){
		for (int i=0;i<s.size() && b>t[1] && a<t[0];++i)
			if (s[i]=='0'){
				s[i]='1';
				++ans;
				--t[0];
				++t[1];
			}
		for (int i=0;i<s.size() && t[0]>a;++i)
			if (s[i]=='0'){
				s[i]='2';
				++ans;
				--t[0];
				++t[2];
			}
		for (int i=0;i<s.size() && t[1]<b;++i)
			if (s[i]=='2'){
				s[i]='1';
				++ans;
				--t[2];
				++t[1];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
	if (a>t[0] && b<t[1]){
		for (int i=0;i<s.size() && a>t[0] && b<t[1];++i)
			if (s[i]=='1'){
				s[i]='0';
				++ans;
				--t[1];
				++t[0];
			}
		for (int i=0;i<s.size() && b<t[1];++i)
			if (s[i]=='1'){
				s[i]='2';
				++ans;
				--t[1];
				++t[2];
			}
		for (int i=0;i<s.size() && a>t[0];++i)
			if (s[i]=='2'){
				s[i]='0';
				++ans;
				--t[2];
				++t[0];
			}
		cout << ans << endl << s << endl;
		return 0;
	}
}
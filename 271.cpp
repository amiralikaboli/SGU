#include <bits/stdc++.h>

using namespace std;

deque <string> deq,oth;

int main(){
	ios::sync_with_stdio(false);
	int n,q,k;
	cin >> n >> q >> k;
	string s;
	for (int i=0;i<n;++i){
		cin >> s;
		if (deq.size()<k)
			deq.push_back(s);
		else
			oth.push_back(s);
	}
	bool b=true;
	for (int i=0;i<q;++i){
		cin >> s;
		if (s[0]=='A'){
			s=s.substr(4,s.size()-5);
			if (deq.size()==k){
				if (b==true){
					deq.push_front(s);
					oth.push_front(deq.back());
					deq.pop_back();
				}
				else{
					deq.push_back(s);
					oth.push_front(deq[0]);
					deq.pop_front();
				}
			}
			else{
				if (b==true)
					deq.push_front(s);
				else
					deq.push_back(s);
			}
		}
		else{
			b=!b;
		}
	}
	if (b==true)
		for (int i=0;i<deq.size();++i)
			cout << deq[i] << "\n";
	else
		for (int i=deq.size()-1;i>=0;--i)
			cout << deq[i] << "\n";
	cerr << endl;
	for (int i=0;i<oth.size();++i)
		cout << oth[i] << endl;
}
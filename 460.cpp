#include <iostream>

using namespace std;

string s[15];

int main (){
	int n;
	cin >> n;
	for (int i=0;i<n;++i)
		cin >> s[i];
	for (int i=0;i<n;++i){
		if (s[i][s[i].size()-1]=='x' || s[i][s[i].size()-1]=='s' || s[i][s[i].size()-1]=='o' || (s[i][s[i].size()-1]=='h' && s[i][s[i].size()-2]=='c'))
			cout << s[i] << "es" << endl;
		else if (s[i][s[i].size()-1]=='y'){
			s[i][s[i].size()-1]='i';
			cout << s[i] << "es" << endl;
		}
		else if (s[i][s[i].size()-1]=='f'){
			s[i][s[i].size()-1]='v';
			cout << s[i] << "es" << endl;
		}
		else if (s[i][s[i].size()-1]=='e' && s[i][s[i].size()-2]=='f'){
			s[i][s[i].size()-2]='v';
			cout << s[i] << "s" << endl;
		}
		else
			cout << s[i] << "s" << endl;
	}
}
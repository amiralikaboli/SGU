#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int t=0;
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (i%3==1 && j%3==1){
				cout << "#";
				++t;
			}
			else if (i%3==0 && j%3==2){
				cout << "#";
				++t;
			}
			else if (i%3==2 && j%3==0){
				cout << "#";
				++t;
			}
			else
				cout << "0";
		}
		cout << endl;
	}
	cerr << t;
}
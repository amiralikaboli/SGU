#include <iostream>
#include <vector>

using namespace std;

bool b[1111];
vector <int> v;

int main (){
	int a,alpha,beta,gamma,m,k;
	cin >> a >> alpha >> beta >> gamma >> m >> k;
	if (k==0){
		cout << a << endl;
		return 0;
	}
	v.push_back(a%m);
	b[a%m]=true;
	int cnt;
	int ind_two;
	for (int i=1; ;++i){
		cnt=alpha*v[i-1]*v[i-1]+beta*v[i-1]+gamma;
		cnt%=m;
		if (b[cnt]==true){
			ind_two=i;
			break;
		}
		b[cnt]=true;
		v.push_back(cnt);
	}
	int ind_one;
	for (int i=0;i<v.size();++i)
		if (v[i]==cnt){
			ind_one=i;
			break;
		}
	if (k<v.size())
		cout << v[k] << endl;
	else{
		k-=ind_one;
		cout << v[k%(ind_two-ind_one)+ind_one] << endl;
	}
}
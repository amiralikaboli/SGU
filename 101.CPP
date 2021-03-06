#include <iostream>
#include <vector>

using namespace std;

int n;
int a[10][10];
bool mark[111],markdomino[111];
vector <int> v;
pair <int,int> p[111];
pair <int,char> saf;
vector <int> pos,neg;

void dfs(int vertex){
	for (int i=0;i<7;++i)
		if (a[vertex][i]!=0){
			--a[vertex][i];
			--a[i][vertex];
			dfs(i);
		}
	v.push_back(vertex);
}

void find(){
	for (int i=0;i<v.size()-1;++i){
		for (int j=0;j<n;++j)
			if (markdomino[j]==false){
				if (v[i]==p[j].first && v[i+1]==p[j].second){
					markdomino[j]=true;
					cout << j+1 << " +" << endl;
					break;
				}
				else if (v[i+1]==p[j].first && v[i]==p[j].second){
					markdomino[j]=true;
					cout << j+1 << " -" << endl;
					break;
				}
			}
	}
}

int main (){
	int m=6;
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> p[i].first >> p[i].second;
		++a[p[i].first][p[i].second];
		++a[p[i].second][p[i].first];
	}
	vector <int> myvec;
	for (int i=0;i<7;++i){
		int cnt=0;
		for (int j=0;j<7;++j)
			cnt+=a[i][j];
		if (cnt%2==1)
			myvec.push_back(i);
	}
	bool b=false;
	if (myvec.size()!=2 && myvec.size()!=0){
		cout << "No solution" << endl;
		return 0;
	}
	if (myvec.size()!=0){
		b=true;
		dfs(myvec[0]);
	}
	if (b==false){
		for (int i=0;i<7;++i)
			for (int j=0;j<7;++j)
				if (a[i][j]>0){
					dfs(i);
					break;
				}
	}
	if (v.size()!=n+1)
		cout << "No solution" << endl;
	else
		find();
	return 0;
}
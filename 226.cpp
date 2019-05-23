#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int Max=200+10;
int n,e;
int d[3*Max];
bool mark[3*Max];
queue <int> q;
vector <int> v[3*Max];

void find(int in,int out,int way){
	if (way==1){
		v[in*3+1].push_back(out*3);
		v[in*3+2].push_back(out*3);
	}
	else if (way==2){
		v[in*3].push_back(out*3+1);
		v[in*3+2].push_back(out*3+1);		
	}
	else if (way==3){
		v[in*3].push_back(out*3+2);
		v[in*3+1].push_back(out*3+2);
	}
}

int bfs (int vertex,int f){
	mark[vertex]=true;
	d[vertex]=0;
	q.push(vertex);
	while (!q.empty()){
		vertex=q.front();
		q.pop();
		for (int i=0;i<v[vertex].size ();++i){
			if (mark[v[vertex][i]]==false){
				mark[v[vertex][i]]=true;
				q.push(v[vertex][i]);
				d[v[vertex][i]]=d[vertex]+1;
			}
		}
	}
	return d[f];
}

int main (){
	cin >> n >> e;
	for (int i=0;i<e;++i){
		int in,out,way;
		cin >> in >> out >> way;
		find(in,out,way);
	}
	v[0].push_back(3);
	v[0].push_back(4);
	v[0].push_back(5);
	v[3*n].push_back(1);
	v[3*n+1].push_back(1);
	v[3*n+2].push_back(1);
	if (bfs(0,1)==0){
		cout << -1;
		return 0;
	}
	cout << bfs(0,1)-2;
}	
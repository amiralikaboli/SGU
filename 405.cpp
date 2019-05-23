#include <iostream>

using namespace std;

int result[111][5],guess[111][111][5];
int point[111];

int ghadr(int x){
	return max(x,-x);
}

int main (){
	int n,k;
	cin >> n >> k;
	for (int i=0;i<k;++i){
		cin >> result[i][1] >> result[i][2];
		for (int j=0;j<n;++j)
			cin >> guess[j][i][1] >> guess[j][i][2];
	}
	for (int i=0;i<k;++i)
		for (int j=0;j<n;++j){
			if ((result[i][1]>result[i][2] && guess[j][i][1]>guess[j][i][2]) || (result[i][1]<result[i][2] && guess[j][i][1]<guess[j][i][2]) || (result[i][1]==result[i][2] && guess[j][i][1]==guess[j][i][2]))
				point[j]+=2;
			if (result[i][1]-result[i][2]==guess[j][i][1]-guess[j][i][2])
				point[j]+=3;
			if (result[i][1]==guess[j][i][1])
				++point[j];
			if (result[i][2]==guess[j][i][2])
				++point[j];
		}
	for (int i=0;i<n;++i)
		cout << point[i] << " ";
}
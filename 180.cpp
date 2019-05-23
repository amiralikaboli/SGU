#include <iostream>
using namespace std;
const int MAX=100*1000+10;
int A[MAX];
int B[MAX];
long long int inv=0;
void merge (int s,int m,int e){
	int i=s;
	int j=m+1;
	for (int t=s;t<=e;++t){
		if (m<i)
			B[t]=A[j++];
		else if (e<j)
			B[t]=A[i++];
		else if (A[i]<=A[j])
			B[t]=A[i++];
		else if (A[i]>A[j]){
			B[t]=A[j++];
			inv+=(m-i+1);
		}
	}
	for (int t=s;t<=e;++t)
		A[t]=B[t];
}
int mergeSort (int s,int e){
	if (s<e){
		int m=(s+e)/2;
		mergeSort (s,m);
		mergeSort (m+1,e);
		merge (s,m,e);
	}
}
int main() {
	int n;
	cin >> n;
	for(int i=0;i<=n-1;++i)
		cin >> A[i];
	mergeSort (0,n-1);
	cout << inv;
}

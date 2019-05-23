#include <iostream>

using namespace std;

int k;
int len;
string s;

int find_mx(int st,int x){
	int mx=-1;
	int ind;
	for (int i=st;i<min(len,st+x+1);++i)
		if (mx<s[i]){
			mx=s[i];
			ind=i;
		}
	return ind;
}

int main(){
	cin >> s >> k;
	len=s.size();
	int index=0;
	while(k>0 && index<len){
		int ind=find_mx(index,k);
		//cerr << s << " " << len << " " << index << " " << ind << "\n";
		if (s[ind]>s[index]){
			for (int i=index;i<len-ind+index;++i)
				s[i]=s[i+ind-index];
			k-=ind-index;
			len-=ind-index;
		}
		++index;
		//cerr << len << " " << k << "\n";
	}
	if (k!=0){
		for (int i=0;i<k;++i){
			int ind;
			int mn=10+'0';
			for (int j=0;j<len;++j)
				if(mn>s[j]){
					ind=j;
					mn=s[j];
				}
			for (int j=ind;j<len-1;++j)
				s[j]=s[j+1];
			--len;
			//cerr << len << " ";
		}
	}
	for (int i=0;i<len;++i)
		cout << s[i];
}
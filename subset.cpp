#include<bits/stdc++.h>
using namespace std;
int main() {
	string set;
	cin>>set;
	int n=set.length();
	int power=1<<n;
	int i, j;
	for(i=0;i<power;i++) {
		string sub="";
		for(j=0;j<n;j++) {
			if((i&(1<<j))!=0)
				sub.push_back(set[j]);
		}
		cout<<'['<<sub<<']'<<endl;
	}
	return 0;
}
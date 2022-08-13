#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int makeGood(int n, string bi) {
	int changes=0;
	int st=bi[0];
	int count=0;
	for(int i=0;i<n;i++) {
		if(bi[i]==st)
			count++;
		else {
			if(count&1) {
				changes++;
				if(i+1<n)
					st=bi[i+1];
				count=0;
			}
			else {
				st=bi[i];
				count=1;
			}
		}
	}
	return changes;
}

int main(void) {
	int t;
	cin>>t;
	int n;
	string bi;
	while(t--) {
		cin>>n;
		cin>>bi;
		cout<<makeGood(n,bi)<<endl;
	}
	return 0;
}
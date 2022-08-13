#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
	vector<bool> visited (n+1,false);
	cout<<2<<endl;
	long k, i = 1;
	for(i = 1 ; i <= n ; i++) {
		if(!visited[i]) {
			k = i;
			while(k <= n) {
				cout<<k<<" ";
				visited[k] = true;
				k = k<<1;
			}
		}
	}
	cout<<endl;
}

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		solve(n);
	}
	return 0;
}
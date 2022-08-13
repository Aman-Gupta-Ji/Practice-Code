#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int main(void) {
	int n;
	cin>>n;
	int e0 = 1, e1 = 1, t;
	for(int i = 2 ; i <= n ; i++) {
		t = e1;
		e1 = e0;
		e0 = (t + e0) % mod;
	}
	int res = (e0 + e1) % mod;
	cout<<res<<endl;
	return 0;
}
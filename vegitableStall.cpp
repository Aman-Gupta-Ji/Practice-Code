#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin>>n;
	vector<int> stall(n);
	sort(stall.begin(), stall.end());
	vector<int> minQ(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		minQ[i] = sum + (n - i - 1) * stall[i];
		sum += stall[i];
	}
	int q, v, res;
	cin>>q;
	for(int i = 0; i < q; i++) {
		cin>>v;
		// function call
		cout<<res<<endl;
	}
	return 0;
}
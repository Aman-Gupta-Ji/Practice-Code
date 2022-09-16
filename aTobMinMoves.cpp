#include<bits/stdc++.h>
using namespace std;

int minMoves(int a, int b) {
	vector<int> dp(b + 1, 1e9);
	dp[a] = 0;
	for(int i = a + 1; i <= b ; i++) {
		if(i % 2 == 0)
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		else
			dp[i] = dp[i - 1] + 1;
	}
	return dp[b];
}

int main(void) {
	int a, b;
	cin>>a>>b;
	cout<<minMoves(a, b)<<endl;
	return 0;
}
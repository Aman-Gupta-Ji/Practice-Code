#include<bits/stdc++.h>
using namespace std;

int n, m, l;
int dp[101][101][101];

bool state(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool dfs(int i, int j, int k, const string& s) {
	if(k == l)
		return true;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
	int oi = i, oj = j;
	char ch = s[k];
	switch(ch) {
		case 'L':
			j++;
			break;
		case 'R':
			j--;
			break;
		case 'F':
			i--;
			break;
		case 'B':
			i++;
			break;
	}
	bool ans = state(i, j) && dfs(i, j, k + 1, s);
	return dp[oi][oj][k] = ans;
}

bool isSafe(const string& s) {
	l = s.length();
	int i, j;
	memset(dp, -1, sizeof(dp));
	bool res = false;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			res = dfs(i, j, 0, s);
			if(res)
				return true;
		}
	}
	return false;
}

int main(void) {
	cin>>n>>m;
	string s;
	cin>>s;
	if(isSafe(s))
		cout<<"Safe"<<endl;
	else
		cout<<"Unsafe"<<endl;
	return 0;
}
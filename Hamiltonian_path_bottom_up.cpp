#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, e;
	cin>>n>>e;

	vector<int> graph[n];
	int s, d;
	for(int i=0;i<e;i++) {
		cin>>s>>d;
		graph[s].push_back(d);
		graph[d].push_back(s);
	}

	int done=1<<n;
	int dp[n][done];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<n;i++) {
		dp[i][1<<i]=1;
	}

	for(int mask=0;mask<done;mask++) {
		for(s=0;s<n;s++) {
			if(dp[s][mask]) {
				for(int de: graph[s]) {
					if(!((mask>>de)&1)) // not visited
						dp[de][mask|(1<<de)]=1;
				}
			}
		}
	}

	bool ans=0;
	for(int i=0;i<n;i++)
		ans |= dp[i][done-1];

	cout<<ans;
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define P(...) (void)printf(VA_ARGS_)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define pb push_back

int dp[3001][3001];

int memo(vector<int>& arr, int l, int r) {
	if(l >= r) {
		return 0;
	}
	if(dp[l][r] != -1)
		return dp[l][r];
	else if(arr[l] == arr[r])
		return memo(arr, l + 1, r - 1);
	int addn;
	addn = min(arr[l] + memo(arr, l + 1, r), arr[r] + memo(arr, l, r - 1));
	return dp[l][r] = addn;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0 ; i < n ; i++) {
		cin>>arr[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<< memo(arr, 0, n -1)<<endl;
}
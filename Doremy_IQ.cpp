#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s, key) (s.find(key) != s.end())
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vi vector<int>
#define vl vector<ll>
#define v(a) vector<a>
#define si set<int>
#define usi unordered_set<int>
#define pii pair<int, int>
#define vpp vector<pair<int, pii>>
#define rset(dp) memset(dp,-1,sizeof(dp))
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vi, greater<int>>
#define print(a) for(auto x : a) cout<<x<<" "; cout<<endl
#define printp(a) for(auto x : a) cout<<x.F<<" "<<x.S<<endl
#define printa(a,x,y) for(int i = x; i < y ; i++) cout<<a[i]<<" "; cout<<endl
#define F first
#define S second
#define pb push_back
#define mii map<int,int>
#define umii unordered_map<int,int>
#define umap unordered_map
#define all(p) b.begin(), p.end()
#define ina(a, n) for(int i=0;i<n;i++) cin>>a[i]
#define inp(a, n) for(int i=0;i<n;i++) cin>>a[i].F>>a[i].S;
#define inq(q,n,t) for(int i=0;i<n;i++) for(int j=0;j<t;j++) cin>>q[i][j]


int dp[1001][1001];
string res;
int mj, n;

int mem(int j, vector<int>& arr, int i, int q, string& state) {
	if(i == n) {
		if(j > mj) {
			mj = 0;
			res = state; 
		}
		return 0;
	}
	if(q == 0) {
		if(j <= mj)
			return 0;
		int ci = i;
		for(;i<n;i++)
			state.push_back('0');
		mem(j, arr, i, q, state);
		for(i=ci;i<n;i++)
			state.pop_back();
		return 0;
	}
	if(q >= n - i) {
		int done = j + n - i;
		if(done <= mj)
			return n-i;
		int ci = i;
		for(;i<n;i++)
			state.push_back('1');
		mem(j, arr, i, q, state);
		for(i=ci;i<n;i++)
			state.pop_back();
		return n-i;
	}
	if(dp[i][q] != -1) {
		int done = dp[i][q] + j;
		if(done <= mj)
			return dp[i][q];
		if(arr[i] <= q) {
			state.push_back('1');
			dp[i][q] = 1 + mem(j+1, arr, i+1, q, state);
			state.pop_back();
		}
		else {
			bool go = dp[i+1][q] >= 1 + dp[i+1][q-1];
			if(go) {
				state.push_back('0');
				mem(j, arr, i+1, q, state);
			}
			else {
				state.push_back('0');
				mem(j+1, arr, i+1, q - 1, state);
			}
			state.pop_back();
		}
		return dp[i][q];
	}
	dp[i][q] = 0;
	if(arr[i] <= q) {
		state.push_back('1');
		dp[i][q] = 1 + mem(j+1, arr, i+1, q, state);
		state.pop_back();
	}
	else {
		state.push_back('1');
		int take = 1 + mem(j+1, arr, i+1, q-1, state);
		state[i]='0';
		int nottake = mem(j, arr, i+1, q, state);
		state.pop_back();
		dp[i][j] = max(take, nottake);
	}
	return dp[i][q];
}

string iq(int size, int q, vector<int>& arr) {
	res="";
	mj = -1;
	n = size;
	string state="";
	if(q>=n) {
		for(int i = 0; i < n ; i++)
			res.push_back('1');
		return res;
	}
	memset(dp, -1, sizeof(dp));
	mem(0, arr, 0, q, state);
	return res;
}
int main(void) {
	fast;
	int t, n, q;
	cin>>t;
	while(t--) {
		cin>>n>>q;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<iq(n,q,arr)<<endl;
	}
	return 0;
}
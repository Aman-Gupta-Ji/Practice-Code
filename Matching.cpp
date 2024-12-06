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

int positive(string& s) {
	if(s[0] == '0')
		return 0;
	int res = 1;
	if(s[0] == '?')
		res = 9;
	int len = s.length();
	for(int i = 1; i < len; i++)
		if(s[i] == '?')
			res *= 10;
	return res;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t;
	cin>>t;
	string s;
	while(t--) {
		cin>>s;
		cout<<positive(s)<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
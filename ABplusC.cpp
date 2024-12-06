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

int goa(ll x, int a) {
	ll c, l = 1, r = 1e6, b;
	while(l <= r) {
		b = l + (r - l) / 2;
		c = x - a * b;
		if(c >=1 && c <= 1e6) {
			cout<<a<<" "<<b<<" "<<c<<endl;
			return 0;
		}
		if(c < 1)
			r = b - 1;
		else
			l = b + 1;
	}
	return b;
}

void abc(ll x) {
	int l = 1, r = 1e6, a, res;
	while(l <= r) {
		a = l + (r - l) / 2;
		res = goa(x, a);
		if(res == 0)
			return;
		if(res == 1)
			r = a - 1;
		else
			l = a + 1;
	}
	cout<<-1<<endl;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t;
	cin>>t;
	ll x;
	while(t--) {
		cin>>x;
		abc(x);
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
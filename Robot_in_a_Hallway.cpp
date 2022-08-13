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

int n;

int recursion(vector<int> arr[2], int i, int j, int vis, int time) {
	if(vis == 2 * n)
		return time;
	if(i == 0) {
		if(j < n - 1 && vis == 2 * j + 1) {
			int t = time;
			if(arr[i][j+1] > time)
				t = arr[i][j+1];
			int right = recursion(arr, i, j+1, vis+1, t+1);
			if(arr[i+1][j] > time)
				time = arr[i+1][j];
			int down = recursion(arr, i+1, j, vis + 1, time+1);

		}
		else {
			if(arr[i][j+1] > time)
				time = arr[i][j+1];
			return recursion(arr, i, j+1, vis+1, time+1);
		}
	}
	else if()
	if(arr[i][j - 1] > time)
		time = arr[i][j - 1];
	return recursion(arr, i, j - 1, vis + 1, time + 1);

}

int main(void) {
	fast;
	clock_t z = clock();
	int t;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr[2];
		arr[0].resize(n);
		arr[1].resize(n);
		for(int i = 0 ; i < n ; i++)
			cin>>arr[0][i];
		for(int i = 0 ; i < n; i++)
			cin>>arr[1][i];
		cout<<recursion(arr, 0, 0, 1, 0)<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
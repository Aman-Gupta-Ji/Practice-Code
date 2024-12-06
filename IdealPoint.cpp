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

const int s = 52;

bool canIdeal(int n, int k, vector<pair<int, int>>& seg) {
	int pref[s] = {0};
	int l, r;
	for(int i = 0; i < n; i++) {
		l = seg[i].first;
		r = seg[i].second;
		if(l == k || r == k) {
			pref[l]++;
			pref[r + 1]--;
		}
	}
	int sum = 0;
	for(int i = 0; i < s; i++)
		pref[i] = sum += pref[i];
	
	for(int i = 0; i < s; i++){
        if(i == k) {
            continue;
        }else {
            if(pref[i] >= pref[k]){
                return false;
            }
        }
    }

    return true;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t, n, k, l, r;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<pair<int, int>> seg(n);
		for(int i = 0; i < n; i++) {
			cin>>l>>r;
			seg[i] = make_pair(l, r);
		}
		if(canIdeal(n, k, seg))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
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

int mod = 998244353;


vector<int> seg_tree;
int query(int l, int r, int s, int e, int index){
    if(l > e || r < s)
    	return 0;
    if(l <= s && r >= e)
    	return seg_tree[index];
    int mid = (s + e) / 2;
    return query(l, r, s, mid, 2 * index + 1) +
    	query(l, r, mid + 1, e, 2 * index + 2);
}

void update(int pos, int s,int e,int index){
    if(pos < s || pos > e)return;
    if(s == e){
        seg_tree[index]++;
        return;
    }
    int mid = (s + e) / 2;
    update(pos, s, mid, 2 * index + 1);
    update(pos, mid + 1, e, 2 * index + 2);
    seg_tree[index] = seg_tree[2 * index + 1]
    				+seg_tree[2 * index + 2];
}

int bpow(int a, ll b) {
    if (b == 0)
        return 1;
    ll res = bpow(a, b / 2);
    if (b % 2)
        return ((res * res)% mod * a) % mod;
    else
        return (res * res) % mod;
}


int countPer(vector<int>& a, int n) {
	seg_tree.resize(4 * n);
	for(int i = 0; i < 4 * n; i++)
		seg_tree[i] = 0;
    vector<int> suffix(n);
    int count = 0, inverse = 0;

    suffix[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = min(suffix[i + 1], a[i]);
    
    for(int i = 0; i < n; i++){
        int no = a[i];
        int add = query(no + 1, n, 0, n + 1, 0);
        if(add == 0 && (i == n-1 || a[i] < suffix[i + 1])) 
            inverse++;
        update(no, 0, n + 1, 0);
        count += add;
    }
    int ans = bpow(2, inverse);
    if(inverse == n)
        return (ans - 1 + mod) % mod;
    else
        return ans;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		cout<<countPer(arr, n)<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
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

void subarr(vector<int>& a, vector<int>& b, int n) {
	int i, l=0,r=0;
	for(i = 0; i < n; i++)
		if(a[i] != b[i])
			break;
	if(i == n) {
	   	for(int i=0;i<n;i++){
	        int last=b[i];
	        int l_local=i,r_local=i;
	        i++;
	        while(i<n&&b[i]>=last){
	            last=b[i];
	            r_local=i;
	            i++;
	        }
	        if(r_local-l_local>r-l){
	            l=l_local;
	            r=r_local;
	        }
	       
	    }
	}
	else {
		l = i;
		for(r = n - 1; r >= 0; r--)
			if(a[r] != b[r])
				break;
		while(l - 1 >= 0 && b[l - 1] <= b[l])
			l--;
		while(r + 1 < n && b[r + 1] >= b[r])
			r++;
	}
    cout<<l+1<<" "<<r+1<<endl;

}

int main(void) {
	fast;
	clock_t z = clock();
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> a(n), ar(n);
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < n; i++)
			cin>>ar[i];
		subarr(a, ar, n);
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
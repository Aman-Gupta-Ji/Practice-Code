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
#define usi uxrdered_set<int>
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
#define umii uxrdered_map<int,int>
#define umap uxrdered_map
#define all(p) b.begin(), p.end()
#define ina(a, n) for(int i=0;i<n;i++) cin>>a[i]
#define inp(a, n) for(int i=0;i<n;i++) cin>>a[i].F>>a[i].S;
#define inq(q,n,t) for(int i=0;i<n;i++) for(int j=0;j<t;j++) cin>>q[i][j]


void ofTwo(int n) {
	string s = to_string(n);
	int l = s.size();
  	vector<int> a(l);
  	int n1 = 0, n2 = 0;
  	int sum = 0;
  	for(int i = 0;i < l; i++){
      	a[i] = s[i] - '0';
      	sum += a[i];
  	}
  	int x = 0,y = 0;
  	if(sum & 1) {
    	x = sum / 2 + 1;
    	y = sum / 2;
  	} else {
    	x = sum / 2;
    	y = sum / 2;
  	}
  	for(int i = 0; i < l; i++) {
    	if(x >= a[i]) {
      		x -= a[i];
      		n1 = n1 * 10 + a[i];
      		a[i]=0;
	    }else {
	        n1 = n1 * 10 + x;
	        a[i] -= x;
	        x = 0;
	    }
  	}
  	for(int i = 0; i < l; i++){
    	if(y >= a[i]) {
       		y -= a[i];
          	n2 = n2 * 10 + a[i];
    	} else {
        	n2 = n2 * 10 + y;
        	y = 0;
    	}
  	}
    cout<<n1<<" "<<n2<<endl;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		ofTwo(n);
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
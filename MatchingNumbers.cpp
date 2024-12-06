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

bool notPossible(long long n) {
	long long sum = n * (2 * n + 1);
    long long l = 1, r = sum / n, val = -1;
    long long mid, sum2, sum1;
    while(l <= r){
        mid = (l + r ) / 2;
        sum1 = (mid * (mid-1) ) / 2;
        sum2 = ((mid + n - 1) * (mid + n)) / 2 - sum1;
        if(sum == sum2){
            val = mid;
            break;
        }
        if(sum1 > sum2)
            r = mid-1;
        else
            l = mid+1;
    }
    if(val == -1){
        cout<<"NO"<<endl;
        return true;
    }
    cout<<"YES"<<endl;
    return false;
}

void match(int n) {
    if(n == 1) {
        cout<<"YES"<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }
    if(notPossible(n))
    	return;
    vector<int> val1(n), val2(n);
    for(int i = 0; i < n; i++)
        val1[i] = 1 + i + n;
    int i, j;
    for(i = 0; 2 * i + 1 <= n; i++)
        val2[i] = 2 * i + 1;
    for(j = 2; i < n; i++, j += 2)
        val2[i] = j;
    for(j = 0, i = n - 1; i >= 0; j++, i--)
        cout<<val2[j]<<" "<<val1[i]<<endl;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		match(n);
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
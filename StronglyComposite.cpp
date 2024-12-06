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

bool sieve[(ll)(1e7 + 2)];
vector<ll> primes;
unordered_map<ll, ll> primesfeq;
ll m;

void primeFactores(ll n) {
	int j = 0;
	while(n>1&&j<primes.size()){
            while(n%primes[j]==0){
                primesfeq[primes[j]]++;
                n/=primes[j];
            }
            j++;
    }
	if(n>1)
        primesfeq[n]++;

}

ll countStronglyC(vector<ll>& arr, ll n) {
	primesfeq.clear();
	ll len = 0, uF = 0;
	for(ll el: arr)
		primeFactores(el);
	for(auto el: primesfeq) {
		ll p = el.second;
		len += p / 2;
		uF += p % 2;
	}
	if(uF == 0)
		return len;
	return len + (uF / 3);
}

int main(void) {
	fast;
	clock_t z = clock();
	ll t, n;
	cin>>t;
	sieve[0] = sieve[1] = true;
    for(ll i = 2; i * i <= 1e7 + 1; i++){
        if(!sieve[i]){
            primes.pb(i);
            for(ll j = i * i; j <= 1e7 + 1; j += i)
                sieve[j] = true;
        }
    }
	while(t--) {
		cin>>n;
		vector<ll> arr(n);
		for(ll i = 0; i < n; i++)
			cin>>arr[i];
		cout<<countStronglyC(arr, n)<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
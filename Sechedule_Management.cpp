#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define has(s, key) (s.find(key) != s.end())
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool cando(vector<int>& val, int t) {
	ll extratime, extra = 0;
	for(int v : val) {
		extratime = t - v;
		if(extratime >= 0)
			extra += extratime/2;
		else {
			if(-extratime > extra)
				return false;
			extra += extratime;
		}
	}
	return true;
}

int solve() {
	int n, m, t;
	cin>>n>>m;
	vector<int> perfect(n, 0);
	for(int i = 0 ; i < m ; i++) {
		cin>>t;
		perfect[t - 1]++;
	}
	sort(perfect.begin(), perfect.end());
	int l = 1, r = m, mid;
	while(l <= r) {
		mid = l + (r - l) / 2;
		if(cando(perfect, mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main(void) {
	fast;
	clock_t z = clock();
	int t;
	cin>>t;
	while(t--) {
		cout<<solve()<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
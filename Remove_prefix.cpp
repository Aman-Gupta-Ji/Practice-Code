#include<bits/stdc++.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define P(...) (void)printf(VA_ARGS_)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define pb push_back

int uniquePrefix(vector<int>& arr, int n) {
	int l, r, el;
	vector<int> feq(n+1, 0);
	for(l = 0, r = 0; r < n; r++) {
		el = arr[r];
		feq[el]++;
		while(feq[el] > 1) {
			feq[arr[l]]--;
			l++;
		}
	}
	return l;
}

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		for(int i = 0 ; i < n; i++)
			cin>>arr[i];
		cout<<uniquePrefix(arr, n)<<endl;
	}
	return 0;
}
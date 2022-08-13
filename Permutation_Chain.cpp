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

void print(vector<int>& arr) {
	for(int a : arr)
		cout<<a<<" ";
	cout<<endl;
}

void solve(int n) {
	vector<int> arr(n);
	for(int i = 1 ; i <= n ; i++)
		arr[i-1] = i;
	int r = n - 1;
	cout<<n<<endl;
	for(int i = 0 ; i < n ; i++) {
		print(arr);
		if(i < n - 1)
			swap(arr[i], arr[i+1]);
	}
}

int main(void) {
	fast;
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		solve(n);
	}
	return 0;
}
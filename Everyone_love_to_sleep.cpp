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

void solve() {
	int n, h, m;
	cin>>n>>h>>m;
	int ah, am;
	int stime = h*60 + m;
	int at;
	int sleep = 24*60;
	for(int i = 0 ; i < n; i++) {
		cin>>ah>>am;
		at = ah*60 + am;
		if(at < stime)
			at += 24*60;
		sleep = min(sleep, at - stime);
	}
	int sh = sleep/60;
	int sm = sleep%60;
	cout<<sh<<" "<<sm<<endl;
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
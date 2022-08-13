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

int solve(int n) {
	if(n == 1)
		return 2;
	if(n % 3 == 0)
		return n / 3;
	if(n % 3 == 1)
		return (n - 4) / 3 + 2;
	else
		return n / 3 + 1;
}

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}
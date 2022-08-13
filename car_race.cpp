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


int main(void) {
	int n;
	cin>>n;
	vector<int> wins(n);
	for(int i = 0 ; i < n ; i++)
		cin>>wins[i];
	int m;
	cin>>m;
	vector<int> ties(n);
	for(int i = 0; i < n; i++)
		cin>>ties[i];
	vector<int> points(n);
	for(int i = 0; i < n; i++) {
		points[i] = 5 * wins[i] + 2 * ties[i];
	}

	cout<<*max_element(points)<<endl;
	return 0;
}
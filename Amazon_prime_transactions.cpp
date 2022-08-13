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

int droppedRequests(vector<int> req) {
	map<int,int> reqests;
	for(int r: req)
		reqests[r]++;
	map<int,int>::iterator st = reqests.begin();
	int dropped = 0, count20 = 0;
	int t, f;
	for(auto i = reqests.begin(); i != reqests.end(); i++) {
		t = i->first;
		dropped += i->second - min(i->second, 3);
		i->second = min(3, i->second);
		while(t - st->first > 10) {
			count20 -= st->second;
			st++;
		}
		if(count20 + i->second > 20) {
			dropped += count20 + i->second - 20;
			i->second = 20 - count20;
		}
		count20 += i->second;

	}
	return dropped;
}


int main(void) {
	fast;
	clock_t z = clock();
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++)
		cin>>arr[i];
	cout<<droppedRequests(arr)<<endl;
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
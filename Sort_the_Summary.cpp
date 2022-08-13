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

bool cmp (vector<int>& a, vector<int>& b) {
	if(a[1] != b[1])
		return a[1] > b[1];
	return a[0] < b[0];
}

vector<vector<int>> groupSort(vector<int>& arr) {
	unordered_map<int,int> feq;
	for(int el: arr)
		feq[el]++;
	vector<vector<int>> res;
	for(auto c: feq)
		res.push_back({c.first, c.second});

	sort(res.begin(), res.end(), cmp);

	return res;
}


int main(void) {
	fast;
	clock_t z = clock();
	
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i < n;i++)
		cin>>arr[i];

	vector<vector<int>> res = groupSort(arr);

	for(auto r: res) {
		for(auto el: r) {
			cout<<el<<" ";
		}
		cout<<endl;
	}


	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
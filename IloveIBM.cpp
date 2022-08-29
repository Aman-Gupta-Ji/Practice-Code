#include<bits/stdc++.h>
using namespace std;

int main(void) {
	unordered_map<string, int> feq;
	int n;
	cin>>n;
	string s;
	for(int i = 0; i < n; i++) {
		cin>>s;
		feq[s]++;
	}
	vector<pair<int,string>> ct;
	for(auto el: feq)
		ct.push_back(make_pair(el.second, el.first));

	ct.sort(ct.begin(), st.end());
	int s = ct.size(), k;
	cin>>k;

	vector<string> res;
	for(int i = s - 1; i >= max(0, s - k); i--)
		res.push_back(ct.second);

	for(int r: res)
		cout<<r<<" ";
	cout<<endl;

	return 0;
}
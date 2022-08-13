#include<bits/stdc++.h>
using namespace std;

int deleteProducts(vector<int>& ids, int m) {
	unordered_map<int,int> feq;
	for(int id: ids)
		feq[id]++;
	vector<int> feqs;
	for(auto el : feq)
		feqs.push_back(el.second);
	sort(feqs.begin(), feqs.end());
	int i, n = feqs.size();
	for(i = 0 ; i < n && m > 0 ; i++) {
		if(feqs[i] <= m)
			m-= feqs[i];
		else {
			i--;
			m = 0;
		}
	}
	return n - i;
}

int main(void) {
	int n, m;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	cin>>m;
	int res = deleteProducts(arr, m);
	cout<<res<<endl;
}
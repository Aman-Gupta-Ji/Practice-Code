#include<bits/stdc++.h>
using namespace std;

bool same(vector<int>& a, vector<int>& b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(int i = a.size() - 1; i >= 0; i--)
		if(a[i] != b[i])
			return false;

	return true;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];

	for(int i = 0; i < n; i++)
		cin>>b[i];

	cout<<same(a, b)<<endl;
	return 0;
}
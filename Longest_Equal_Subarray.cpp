#include<bits/stdc++.h>
using namespace std;

int lontestEqualSubarray(vector<int>& Arr, int n) {
	int ans = 0;
	unordered_map<int, int> feq;
	int len;
	for(int l = 0, r = 0; r < n; r++) {
		len = r - l + 1;
		feq[Arr[r]]++;
		while(feq[Arr[r]] + feq[Arr[r] - 1] != len && feq[Arr[r]] + feq[Arr[r] + 1] != len) {
			feq[Arr[l]]--;
			l++;
			len = r - l + 1;
		}
		ans = max(ans, len);
	}
	return ans;
}

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> Arr(n);
		for(int i = 0; i < n; i++)
			cin>>Arr[i];
		cout<<lontestEqualSubarray(Arr, n)<<endl;
	}	
	return 0;
}
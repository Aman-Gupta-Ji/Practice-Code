#include<bits/stdc++.h>
using namespace std;

int trips(int n) {
	if(n == 1)
		return -1;
	if(n % 3 == 0)
		return n / 3;
	if(n % 3 == 1)
		return (n - 4) / 3 + 2;
	else
		return n / 3 + 1;
}

int getMinimumTrips(vector<int>& weights) {
	unordered_map<int,int> feq;
	for(int w: weights)
		feq[w]++;

	int res = 0;
	for(auto el: feq) {
		int trip = trips(el.second);
		if(trip == -1)
			return -1;
		res += trip;
	}
	return res;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> weights(n);
	for(int i = 0; i < n; i++)
		cin>>weights[i];
	cout<<getMinimumTrips(weights)<<endl;
	return 0;
}
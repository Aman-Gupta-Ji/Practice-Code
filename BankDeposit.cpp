#include<bits/stdc++.h>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
int cs = 15;

vector<int> lap;

bool great(vector<int>& c) {
	for(int i = 0; i < 15; i++)
		if(c[i] < lap[i])
			return false;
	return true;
}

vector<int> minCoin(int A) {
	vector<int> c(15, 0);
	for(int i = 14; i >= 0; i--) {
		c[i] = A / coins[i];
		A -= coins[i] * c[i];
	}
	return c;
}


bool atAmount(int a) {
	vector<int> c = minCoin(a);
	return great(c);
}

int maxCoins(int C, int L) {
	int l = L, r = C, mid;
	while(l <= r) {
		mid = l + (r - l) / 2;
		if(atAmount(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}

int main(void) {
	int C, L;
	cin>>C>>L;
	lap = minCoin(L);
	cout<<maxCoins(C, L)<<endl;
	return 0;
}
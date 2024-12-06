#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7, block_size;
int *rsm;

int _lcm(long a, long b) {
	return (a * b / __gcd(a, b)) % mod;
}

int* createBlocks(int arr[], int n) {
	block_size = ceil(sqrt(n));
	int *blocks = new int[block_size];
	fill(blocks, blocks + block_size, 1);

	for(int i = 0; i < n; i++)
		blocks[i / block_size] = _lcm(blocks[i / block_size], arr[i]);

	return blocks;
}

int fun(int arr[], int l, int r) {
	int start = l / block_size, end = r / block_size;
	int lcm = 1;

	if(start == end) {
		for(int i = l; i <= r; i++)
			lcm = _lcm(lcm, arr[i]);
		
		return lcm;
	}

	for(int i = start + 1; i < end; i++)
		lcm = _lcm(lcm, rsm[i]);

	int i = l;
	while(i / block_size == start)
		lcm = _lcm(lcm, arr[i++]);

	i = r;
	while(i / block_size == end) {
		lcm = _lcm(lcm, arr[i--]);
	}

	return lcm;
}

int main(void) {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	rsm = createBlocks(arr, n);


	int q, l, r;
	cin>>q;
	while(q--) {
		cin>>l>>r;
		cout<<fun(arr, l, r)<<endl;
	}
	return 0;
}
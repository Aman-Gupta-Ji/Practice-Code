// Given a number, find the set bits in a number using a recursive function.

#include<bits/stdc++.h>
using namespace std;

int count(int n, long p) {
	if(p > n)
		return 0;
	return ((n & p) > 0) + count(n, p << 1);
}

void recursion(int n, long p, int i) {
	if(p > n)
		return;
	if(n & p)
		cout<<i<<" ";
	recursion(n, p << 1, i + 1);
}

int main(void) {
	int n;
	cin>>n;
	recursion(n, 1, 0);
	cout<<endl<<count(n, 1)<<endl;
	return 0;
}
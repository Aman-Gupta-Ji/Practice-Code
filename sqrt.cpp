#include<iostream>
using namespace std;

int sqrt(int n) {
	if(n < 0)
		return -1;
	int l = 0, r = n;
	long sq, mid;
	while(l <= r) {
		mid = l + (r - l) / 2; 
		sq = mid * mid;
		if(sq == n)
			return mid;
		if(sq > n)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int main(void) {
	int n;
	cin>>n;
	cout<<sqrt(n)<<endl;
	return 0;
}
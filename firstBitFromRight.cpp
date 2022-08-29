#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin>>n;
	if(n == 0) {
		cout<<0<<endl;
		return 0;
	}
	int pos = 1;
	while(n != 0) {
		if(n & 1)
			break;
		pos++;
		n = n >> 1;
	}
	cout<<pos<<endl;
	return 0;
}
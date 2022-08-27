#include<bits/stdc++.h>
using namespace std;

int main(void) {

	int k;
	cin>>k;
	string s; 
	cin>>s;

	int g0 = 0, l0 = 0;
	int i, n = s.length();

	char prev = '1';

	while(k--) {
		for (i = 0; i < n; i++) {
			switch(s[i]) {
				case '1':
					l0 = 0;
					break;
				case '0':
					l0++;
					g0 = max(g0, l0);
					break;
			} 
			prev = s[i];
		}
	} 
	cout<<g0<<endl;
	return 0;
}
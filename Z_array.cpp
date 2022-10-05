#include<bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	cin>>s;
	int n = s.length();
	vector<int> z(n);
	z[0] = n;
	int l, r, k, c;
	
	cout<<"Z Array"<<endl;

	l = r = 0;
	for(int i = 1; i < n; i++) {
		if(i < r) {
			k = i - l;
			if(z[k] < r - i + 1)
				z[i] = z[k];
			else {
				c = i + z[k];
				while(s[c] == s[r] && r < n) {
					c++;
					r++;
				}
				r--;
				z[i] = r - i + 1;
			}
		}
		else {
			l = r = i;
			c = 0;
			while(s[c] == s[r] && r < n) {
				c++;
				r++;
			}
			r--;
			z[i] = r - i + 1;
		}
	}

	for(int& p: z)
		cout<<p<<" ";
	cout<<endl;

	return 0;
}
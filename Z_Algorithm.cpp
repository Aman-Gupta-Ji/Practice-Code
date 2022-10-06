#include<bits/stdc++.h>
using namespace std;

vector<int> z_array(string s, int n) {
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

	return z;
}

int main(void) {
	string s, pat;
	cin>>s>>pat;
	int n = s.length(), m = pat.length(), len = n + m + 1;
	vector<int> z = z_array(pat + "#" + s, len);
	for(int i = m + 1; i < len; i++)
		if(z[i] == m) {
			cout<<"FOUND "<<i - m - 1<<endl;
			return 0;
		}
	cout<<"NOT FOUND"<<endl;
	return 0;
}
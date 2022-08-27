#include<bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	cin>>s;
	int feq[3] = {0};
	int n = s.length();
	int c = 0;
	int sub = 0;
	for(int l = 0, r = 0; r < n; r++) {
		if(s[r] < 'd') {
			feq[s[r] - 'a']++;
			if(feq[s[r] - 'a'] == 1)
				c++;
			while(c == 3) {
				if(s[l] < 'd') {
					feq[s[l] - 'a']--;
					if(feq[s[l] - 'a'] == 0)
						c--;
				}
				l++;
			}
		}
		sub += r - l + 1;
	}
	cout<<sub<<endl;
	return 0;
}
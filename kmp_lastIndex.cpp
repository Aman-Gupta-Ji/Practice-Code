// Given a String and pattern Find the last occurrence of the pattern in the given string. KMP

#include<bits/stdc++.h>
using namespace std;

// bcabcabb

vector<int> lpsArray(string s) {
	int n = s.length();
	vector<int> lps(n);
	lps[0] = 0;

	cout<<"LPS Array\n"<<s<<endl;

	int len = 0;
	int i = 1;
	while(i < n) {
		if(s[len] == s[i]) {
			lps[i] = len + 1;
			len++;
			i++;
		}
		else {
			if(len != 0)
				len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	for(int i: lps)
		cout<<i<<" ";
	cout<<endl;

	return lps;
}

int main(void) {
	string s, pat;
	cin>>s>>pat;

	int n = s.length(), m = pat.length();
	vector<int> lps = lpsArray(pat);

	int ind = -1;

	int len = 0;
	for(int i = 0; i < n;) {
		if(len < m && s[i] == pat[len]) {
			i++;
			len++;
		}
		else {
			if(len != 0)
				len = lps[len - 1];
			else
				i++;
		}
		if(len == m)
			ind = i - m;
	}

	if(ind == -1)
		cout<<"NOT FOUND"<<endl;
	else
		cout<<"LAST FOUND "<<ind<<endl;

	return 0;
}
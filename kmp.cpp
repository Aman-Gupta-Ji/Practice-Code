#include<bits/stdc++.h>
using namespace std;

int main(void) {
	string s, pat;
	cin>>s>>pat;
	int n = s.length(), m = pat.length();
	vector<int> lps(m);
	lps[0] = 0;
	cout<<"LPS Array"<<endl;
	for(int i = 0, j = 1; j < m;) {
		if(pat[i] == pat[j]) {
			i++;
			lps[j] = i;
			j++;
		}
		else if(i != 0) {
			i = lps[i - 1];
		}
		else {
			lps[j] = 0;
			j++;
		}
	}
	for(int l: lps)
		cout<<l<<" ";
	cout<<endl;
	for(int i = 0, j = 0; i < n;) {
		if(s[i] == pat[j]) {
			i++;
			j++;
		}
		else if(j != 0)
			j = lps[j - 1];
		else
			i++;
		if(j == m) {
			cout<<"FOUND "<<i - m<<endl;
			return 0;
		}
	}
	cout<<"NOT FOUND"<<endl;
	return 0;
}
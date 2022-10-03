#include<bits/stdc++.h>
using namespace std;

bool TMT(string& s, int n) {
	int T, M, cM;
	T = M = cM = 0;
	for(char& ch: s)
		if(ch == 'M')
			cM++;
	for(char& ch: s) {
		if(ch == 'M') {
			if(T == 0)
				return false;
			T--;
			M++;
		}
		else {
			if(cM > 0 || M == 0) {
				T++;
				cM--;
			}
			else
				M--;
		}
	}
	return T == 0 && M == 0;
}

int main(void) {
	int t, n;
	cin>>t;
	string s;
	while(t--) {
		cin>>n>>s;
		if(TMT(s, n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
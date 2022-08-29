#include<bits/stdc++.h>
using namespace std;

int main(void) {
	string s;
	cin>>s;
	int r;
	cin>>r;
	vector<pair<char,int>> st;
	pair<char, int> pre;
	char ch;
	int feq;
	for(char c: s) {
		if(st.empty())
			st.push_back(make_pair(c, 1));
		else {
			pre = st.back();
			ch = pre.first;
			feq = pre.second;
			if(c == ch)
				st.push_back(make_pair(c, feq + 1));
			else
				st.push_back(make_pair(c, 1));
		}
		pre = st.back();
		feq = pre.second;
		if(feq == r) {
			while(feq--)
				st.pop_back();
		}
	}
	string res = "";
	for(auto el: st)
		res.push_back(el.first);

	cout<<res<<endl;
	return 0;
}
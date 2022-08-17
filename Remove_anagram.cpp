#include<bits/stdc++.h>
using namespace std;

vector<string> removeAnagram(vector<string>& textList) {
	unordered_map<string,string> uniq;
	for(auto text: textList) {
		string st = text;
		sort(st.begin(), st.end());
		if(uniq.find(st) == uniq.end())
			uniq[st] = text;
	}
	vector<string> res;
	for(auto el: uniq)
		res.push_back(el.second);
	sort(res.begin(), res.end());
	return res;
}

int main(void) {
	int n;
	cin>>n;
	vector<string> text(n);
	for(int i = 0; i < n; i++)
		cin>>text[i];
	vector<string> res = removeAnagram(text);
	for(auto r: res)
		cout<<r<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int minChange(const string& s) {
	int len = s.length();
	int change = 0, last = -1;
	for(int i = 1 ; i < len ; i++) {
		if(s[i] == s[i -1 ] && last != i - 1) {
			change++;
			last = i;
		}
	}
	return change;
}

vector<int> minimalOperations(vector<string>& words) {
	int n = words.size();
	vector<int> res(n);
	for(int i = 0 ; i < n ; i++)
		res[i] = minChange(words[i]);
	return res;
}

int main(void) {
	int n;
	cin>>n;
	vector<string> arr(n);
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	vector<int> res = minimalOperations(arr);
	for(int i = 0 ; i < n ; i++)
		cout<<res[i]<<endl;
}
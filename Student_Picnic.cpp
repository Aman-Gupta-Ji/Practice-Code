#include<bits/stdc++.h>
using namespace std;

int maxGroups(vector<int>& cop, int n) {
	int group = 0;
	int l, r;
	unordered_map<int,int> avail;
	for(l = 0, r = 0; r < n; r++) {
		avail[cop[r]]++;
		if(avail[cop[r]] > 1) {
			group++;
			while(l <= r) {
				avail[cop[l]]--;
				l++;
			}
		}
	}
	return group;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> cop(n);
	for(int i = 0; i < n; i++)
		cin>>cop[i];
	cout<<maxGroups(cop, n);
	return 0;
}
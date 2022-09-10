#include<bits/stdc++.h>
using namespace std;
vector<int> elements(int q, vector<vector<int>>& query) {
	int maxf=0;
	unordered_map<int,int> freq;
	unordered_map<int,stack<int>> freqSt;
	vector<int> res;
	int c, el;
	for(int i=0;i<q;i++) {
		c=query[i][0];
		switch(c) {
			case 1:
				el=query[i][1];
				freq[el]++;
				maxf=max(maxf,freq[el]);
				freqSt[freq[el]].push(el);
				break;
			case 2:
				if(maxf==0) {
					res.push_back(-1);
					break;
				}
				el=freqSt[maxf].top();
				freq[el]--;
				freqSt[maxf].pop();
				if(freqSt[maxf].empty())
					maxf--;
				res.push_back(el);
				break;
		}
	}
	return res;
}
int main(void) {
	int q;
	cin>>q;
	vector<vector<int>> query;
	int c, el;
	for(int i=0;i<q;i++) {
		cin>>c>>el;
		query.push_back({c,el});
	}
	vector<int> res=elements(q,query);
	for(int r: res)
		cout<<r<<" ";
	return 0;
}
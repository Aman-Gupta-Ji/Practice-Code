#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int minOp(vector<int>& ar, int n) {
	int count0=0;
	unordered_map<int,int> freq;
	bool copy=false;
	for(int i=0;i<n;i++) {
		if(ar[i]==0)
			count0++;
		freq[ar[i]]++;
		if(freq[ar[i]]>1)
			copy=true;
	}
	if(count0==0)
		return n+((copy)?0:1);
	return n-count0;
}
int main(void) {
	int t;
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		vector<int> ar(n);
		for(int i=0;i<n;i++)
			cin>>ar[i];
		cout<<minOp(ar,n)<<endl;
	}
	return 0;
}
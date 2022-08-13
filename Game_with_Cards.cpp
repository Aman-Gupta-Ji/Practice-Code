#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int t, n, m, i, val;
	int maxA, maxB;
	cin>>t;
	while(t--) {
		cin>>n;
		maxA=maxB=0;
		for(i=0;i<n;i++) {
			cin>>val;
			maxA=max(maxA,val);
		}
		cin>>m;
		for(i=0;i<m;i++) {
			cin>>val;
			maxB=max(maxB,val);
		}
		if(maxA>maxB)
			cout<<"Alice"<<endl<<"Alice"<<endl;
		else if(maxA<maxB)
			cout<<"Bob"<<endl<<"Bob"<<endl;
		else
			cout<<"Alice"<<endl<<"Bob"<<endl;
	}
	return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int t, n;
	cin>>t;
	string pal;
	char common;
	int res, pos, i;
	while(t--) {
		cin>>n;
		cin>>pal;
		pos=n/2;
		common=pal[pos];
		res=1;
		for(i=pos-1;i>=0;i--) {
			if(pal[i]!=common)
				break;
			res++;
		}
		for(i=pos+1;i<n;i++) {
			if(pal[i]!=common)
				break;
			res++;
		}
		cout<<res<<endl;

	}
	return 0;
}
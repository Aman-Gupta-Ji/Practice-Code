#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int n, k;
	cin>>n>>k;
	int sq=k*k;
	int count=0;
	for(int i=1;i<=n;i++) {
		if(i%k==0&&i%sq!=0)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
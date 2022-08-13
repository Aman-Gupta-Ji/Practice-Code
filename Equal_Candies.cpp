#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int t;
	cin>>t;
	int n;
	int minc;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		minc=INT_MAX;
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			minc=min(arr[i],minc);
		}
		int ans=0;
		for(int i=0;i<n;i++)
			ans+=arr[i]-minc;
		cout<<ans<<endl;
	}
	return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int minSimilar(vector<string>& arr, int n, int m) {
	int minc=INT_MAX;
	int i, j, cost, k;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {
			cost=0;
			for(k=0;k<m;k++)
				cost+=abs(arr[i][k]-arr[j][k]);
			minc=min(minc,cost);
		}
	}
	return minc;
}

int main(void) {
	int t;
	cin>>t;
	int n, m, i;
	while(t--) {
		cin>>n>>m;
		vector<string> arr(n);
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<minSimilar(arr,n,m)<<endl;
	}
	return 0;
}
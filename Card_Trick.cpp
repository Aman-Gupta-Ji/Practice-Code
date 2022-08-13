#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int solve(vector<int>& arr, int n, int m, vector<int>& sw) {
  	int swaps=0, el;
  	for(int i=0;i<m;i++){
      el=sw[i];
      swaps=(swaps+el)%n;
  	}
  	return arr[swaps];
}

int main(void) {
	int t, n, i, m;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> deck(n);
		for(i=0;i<n;i++)
			cin>>deck[i];
		cin>>m;
		vector<int> sw(m);
		for(i=0;i<m;i++)
			cin>>sw[i];
		cout<<solve(deck,n,m,sw)<<endl;
	}
	return 0;
}
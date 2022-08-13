#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll find_fuel(vector<int>& A, int l, int r, int x, int y) {
	vector<int> arr(A.begin()+l,A.begin()+r);
	sort(arr.begin(),arr.end());
	ll sum=0;
	int i, n=r-l;
	for(i=0;i<x;i++)
		sum+=arr[i];
	for(;i<n&&arr[i]<0&&i<y;i++)
		sum+=arr[i];
	return sum;
}

vector<ll> min_emission_SAF(int n, vector<int>& A, int q, vector<vector<int>>& Q) {
	vector<ll> res;
	int l, r, x, y;
	ll ret;
	for(vector<int> query: Q) {
		l=query[0];
		r=query[1];
		x=query[2];
		y=query[3];
		ret=find_fuel(A,l,r,x,y);
		res.push_back(ret);
	}
	return res;
}

int main() {
	int t, n, q, i;
	int l, r, x, y;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> A(n);
		for(i=0;i<n;i++)
			cin>>A[i];
		cin>>q;
		vector<vector<int>> Q;
		for(i=0;i<q;i++) {
			cin>>l>>r>>x>>y;
			l--;
			Q.push_back({l,r,x,y});
		}
		vector<ll> res=min_emission_SAF(n,A,q,Q);
		for(i=0;i<q;i++)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}
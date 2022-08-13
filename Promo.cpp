#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(void) {
	int n, q;
	cin>>n>>q;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end(),greater<int>());
	vector<ll> prefix(n);
	prefix[0]=arr[0];
	for(int i=1;i<n;i++)
		prefix[i]=prefix[i-1]+arr[i];
	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// 	cout<<prefix[i]<<" ";
	// cout<<endl;
	int x, y;
	while(q--) {
		cin>>x>>y;
		if(x==y) {
			cout<<prefix[x-1]<<endl;
			continue;
		}
		cout<<prefix[x-1]-prefix[x-y-1]<<endl;
	}
	return 0;
}
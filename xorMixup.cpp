#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vl vector<ll>
#define vi vector<int>
#define has(s,a) s.find(a)!=s.end()

int main(void) {
	int t, n, i, x;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		x=0;
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<arr[0]<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vl vector<ll>
#define vi vector<int>
#define has(s,a) s.find(a)!=s.end()

int main(void) {
	int t, n, k, i;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vi arr(n);
		for(i=0;i<n;i++)
			cin>>arr[i];
		if(k==1)
			cout<<n/2-((n&1)==0)<<endl;
		else {
			int ans=0;
			for(i=1;i<n-1;i++) {
				if(arr[i]>arr[i-1]+arr[i+1])
					ans++;
			}
			cout<<ans<<endl;
		}
	}
}
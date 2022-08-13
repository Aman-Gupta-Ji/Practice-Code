#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int energy(int n, int m, vector<int>& arr){
	ll sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	if(m>=sum)
		return 0;
	else
		return sum-m;
}
int main(void) {
	int t;
	int n, m, i;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		vector<int> arr(n);
		for(i=0;i<n;i++)
			cin>>arr[i];
		cout<<energy(n,m,arr)<<endl;
	}
	return 0;
}
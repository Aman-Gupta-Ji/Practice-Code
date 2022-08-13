#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool can_equal(vector<int>& arr, int n) {
	double sum=0;
	for(int a: arr)
		sum+=a;
	for(int a: arr)
		if((sum-a)/(n-1)==a)
			return true;
	return false;
}

int main(void) {
	int t, n, i;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		for(i=0;i<n;i++)
			cin>>arr[i];
		if(can_equal(arr,n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
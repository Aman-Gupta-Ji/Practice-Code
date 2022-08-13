#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int> circularMinMax(vector<int>& arr, int n) {
	
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<int> res=circularMinMax(arr,n);
		if(res.size()>0) {
			cout<<"YES"<<endl;
			for(int a: res)
				cout<<a<<" ";
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int res, maxel;
		res=maxel=0;
		for(int el: arr) {
			if(maxel>el) {
				res++;
				maxel=0;
			}
			else
				maxel=max(el,maxel);
		}
		cout<<res<<endl;
	}
	return 0;
}
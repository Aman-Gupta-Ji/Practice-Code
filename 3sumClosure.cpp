#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vl vector<ll>
#define vi vector<int>
#define has(s,a) (s.find(a)!=s.end())

bool threeSum(vi& arr, int n) {
	int ps=0, ng=0, z=0;
	vector<int> all;
	unordered_map<int,int> feq;
	for(int el: arr) {
		if(el<0)
			ng++;
		else if(el>0)
			ps++;
		else
			z++;
		feq[el]++;
		if(feq[el]<4)
			all.push_back(el);
	}
	if(ps>2||ng>2)
		return false;
	if(z!=0&&(ng==2||ps==2))
		return false;
	int i, j, k, s=all.size();
	for(i=0;i<s;i++) {
		for(j=i+1;j<s;j++) {
			for(k=j+1;k<s;k++) {
				if(!has(feq,all[i]+all[j]+all[k]))
					return false;
			}
		}
	}
	return true;
}
int main(void) {
	int t, i, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vi arr(n);
		for(i=0;i<n;i++)
			cin>>arr[i];
		if(threeSum(arr,n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
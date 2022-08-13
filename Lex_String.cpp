#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(void) {
	int t;
	cin>>t;
	int n, m, k;
	string a, b;
	int i, j;
	int streak;
	bool takea=true;
	string c;
	while(t--) {
		cin>>n>>m>>k;
		cin>>a>>b;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		c="";
		i=0, j=0;
		streak=0;
		while(i<n&&j<m) {
			if(streak==k) {
				if(takea)
					c+=b[j++];
				else
					c+=a[i++];
				streak=0;
				takea=!takea;
			}
			else if(a[i]<b[j]) {
				// cout<<c<<":\n";
				c+=a[i++];
				if(!takea) {
					takea=true;
					streak=0;
				}
			}
			else {
				// cout<<c<<":\n";
				c+=b[j++];
				if(takea) {
					takea=false;
					streak=0;
				}
			}
			streak++;
		}
		cout<<c<<endl;
	}
	return 0;
}
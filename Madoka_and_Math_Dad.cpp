#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vl vector<ll>
#define has(s,a) s.find(a)!=s.end()

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		while(n>0) {
			switch(n) {
				case 1:
					cout<<1;
					n-=1;
					break;
				case 2:
					cout<<2;
					n-=2;
					break;
				default:
					if(n%3==1)
						cout<<12;
					else
						cout<<21;
					n-=3;
					break;
			}
		}
		cout<<endl;
	}
}
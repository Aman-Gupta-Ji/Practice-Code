#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s, key) (s.find(key) != s.end())
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(void) {
	fast;
	clock_t z = clock();
	int t, g, i;
	cin>>t;
	while(t--) {
		int count = 0;
		for(int i = 0 ; i < 4 ; i++) {
			cin>>g;
			count += g;
		}
		switch(count) {
			case 0:
				cout<<0;
				break;
			case 1:
			case 2:
			case 3:
				cout<<1;
				break;
			case 4:
				cout<<2;
				break;
		}
		cout<<endl;
	}
	cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
	return 0;
}
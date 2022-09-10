#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define vl vector<ll>
#define has(s,a) s.find(a)!=s.end()

bool isPrime(int n) {
	int sq=(int)sqrt(n);
	for(int i=2;i<=sq;i++)
		if(n%i==0)
			return false;
	return true; 
}

int main(void) {
	int t;
	cin>>t;
	int n, d, sq, left;
	while(t--) {
		cin>>n>>d;
		if(n%d!=0)
			cout<<"NO"<<endl;
		else {
			sq=d*d;
			if(n%sq==0) {
				left=n/sq;
				cout<<left<<" ";
				if(!isPrime(left)&&left%d!=0)
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, m;
	cin>>n>>m;
	long long k=n/m;
	if(k*m!=n)
		cout<<(k+1)<<endl;
	else
		cout<<k<<endl;
	return 0;
}
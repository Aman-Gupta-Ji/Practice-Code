#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

bool lucky(string& ticket) {
	int first=ticket[0]+ticket[1]+ticket[2];
	int last=ticket[3]+ticket[4]+ticket[5];
	return first==last;
}

int main(void) {
	int t;
	cin>>t;
	string ticket;
	while(t--) {
		cin>>ticket;
		if(lucky(ticket))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
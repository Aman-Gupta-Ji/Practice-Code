#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define has(s, key) (s.find(key) != s.end())

int main(void) {
	int s, t, q;
	cin>>s>>t>>q;
	int seat;
	unordered_set<int> booked;
	//booked seats
	for(int i = 0 ; i < t ; i++) {
		cin>>seat;
		booked.insert(seat);
	}
	//prefered seats
	for(int i = 0 ; i < q ; i++) {
		cin>>seat;
		if(has(booked, seat))
			cout<<"N"<<endl;
		else
			cout<<"Y"<<endl;
	}
	return 0;
}
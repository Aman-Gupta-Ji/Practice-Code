#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int t;
	cin>>t;
	queue<string> q;
	int c;
	string color;
	while(t--) {
		cin>>c;
		switch(c) {
			case 1:
				cin>>color;
				q.push(color);
				break;
			case 2:
				color=q.front();
				q.pop();
				cout<<color<<endl;
				q.push(color);
				break;
		}
	}
	return 0;
}
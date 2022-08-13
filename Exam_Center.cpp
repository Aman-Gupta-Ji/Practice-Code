#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s, key) (s.find(key) != s.end())
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(void) {
	int n;
	cin>>n;
	int r = 0;
	string room;
	while(n != 0 ) {
		r++;
		room = to_string(r);
		if(room.find("2") == string::npos && room.find("14") == string::npos)
			n--;
	}
	cout<<r;
	return 0;
}
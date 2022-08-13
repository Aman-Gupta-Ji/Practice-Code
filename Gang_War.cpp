#include<bits/stdc++.h>
using namespace std;

bool sameAxis(set<int>& ky, int y) {
	// cout<<y<<" : ";
	// for(int x : ky)
		// cout<<x<<" < ";
	// cout<<endl;
	auto lb = ky.lower_bound(y);
	if(lb == ky.end())
		return false;
	if(*lb > y && lb == ky.begin())
		return false;
	// cout<<"yes"<<endl;
	return true;
}

int Killer(vector<pair<int,int>>& kill, vector<pair<int,int>>& die, int n) {
	map<int, set<int>> kx, ky;
	int x, y;
	for(int i = 0 ; i < n ; i++) {
		x = kill[i].first;
		y = kill[i].second;
		kx[x].insert(y);
		ky[y].insert(x);
	}
	int died = 0;
	for(int i = 0 ; i < n ; i++) {
		x = die[i].first;
		y = die[i].second;
		if(sameAxis(kx[x], y)) {
			died++;
			// cout<<x<<" "<<y<<endl;
		}
		else if(sameAxis(ky[y], x)) {
			died++;
			// cout<<x<<" "<<y<<endl;
		}
	}
	return died;
}

int main(void) {
	int n;
	cin>>n;
	vector<pair<int,int>> M(n), L(n);
	int x, y;
	for(int i = 0 ; i < n ; i++) {
		cin>>x>>y;
		M[i]=make_pair(x,y);
	}
	for(int i = 0 ; i < n ; i++) {
		cin>>x>>y;
		L[i]=make_pair(x,y);
	}
	int Mkilled = Killer(L, M, n);
	int Lkilled = Killer(M, L, n);
	int totoalKill = Mkilled + Lkilled;
	cout<<totoalKill<<endl;
	cout<<"MOOSE "<<Mkilled<<" "<<(n - Mkilled)<<endl;
	cout<<"LAWREN "<<Lkilled<<" "<<(n - Lkilled)<<endl;
	return 0;
}
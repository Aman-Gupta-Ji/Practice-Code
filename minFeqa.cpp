#include<bits/stdc++.h> 
using namespace std;

int main(void) { 
	int n, a; 
	cin>>n; 
	map<int, int> feq;

	for(int i = 0; i < n; i++) { 
		cin>>a; 
		feq[a]++;
	} 

	cin>>a;
	for (auto el: feq) { 
		if(el.second a) { 
			cout<<el.first<<endl;
			return 0;
		}
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int a, b;
	cin>>a>>b;
	vector<vector<int>> mat(a, vector<int> (b + 1, 0));
	int r;
	cin>>r;
	int s, e, ro;
	for(int i = 0; i < r; i++) {
		cin>>ro>>s>>e;
		ro--;
		s--;
		mat[ro][s]++;
		mat[ro][e]--;
	}
	int i, j;
	int count0 = 0;
	for(i = 0; i < a; i++) {
		if(mat[i][0] == 0)
			count0++;
		for(j = 1; j < b; j++) {
			mat[i][j] += mat[i][j - 1]; 
			if(mat[i][j] == 0)
				count0++;
		}
	}

	cout<<count0<<endl;
	return 0;
}
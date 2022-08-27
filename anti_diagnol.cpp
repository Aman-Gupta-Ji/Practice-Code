#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int k;
	cin>>k;
	vector<vector<int>> mat(k, vector<int>(k));
	int i, j;
	for(i = 0; i < k; i++)
		for(j = 0; j < k; j++)
			cin>>mat[i][j];
	for(int d = 0; d < k ; d++) {
		i = 0;
		j = d;
		while(i < k && j >= 0) {
			cout<<mat[i][j]<<" ";
			i++;
			j--;
		}
	}
	for(int d = 1; d < k; d++) {
		i = d;
		j = k - 1;
		while(i < k && j >= 0) {
			cout<<mat[i][j]<<" ";
			i++;
			j--;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int getMaximumGreyness(vector<vector<int>>& pixel) {
	int n = pixel.size();
	int m = pixel[0].size();
	vector<int> row(n), column(m);
	int i, j;
	int sum;
	for(i = 0; i < n; i++) {
		sum = 0;
		for(j = 0; j < m; j++) {
			switch(pixel[i][j]) {
				case 0:
					column[j]--;
					sum--;
					break;
				case 1:
					column[j]++;
					sum++;
					break;
			}
		}
		row[i] = sum;
	}
	int maxGrey = row[0] + column[0];
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			maxGrey = max(maxGrey, row[i] + column[j]);
		}
	return maxGrey;
}

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> pixel(n, vector<int>(m));
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			cin>>pixel[i][j];
		}
	}
	cout<<getMaximumGreyness(pixel);
	return 0;
}
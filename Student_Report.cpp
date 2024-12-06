#include<bits/stdc++.h>
using namespace std;

Result

vector<int> SortStudentMarks(int n, int m, vector<vector<int>>& marks) {

}

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> marks(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>marks[i][j];
	vector<int> output = SortStudentMarks(n, m, marks);
	for(int i = 0; i < n; i++) {
		cout<<output[i]<<" ";
	}
	return 0;
}
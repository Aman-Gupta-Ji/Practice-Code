#include<bits/stdc++.h>
using namespace std;

int minSteps(int input1, int input2) {
	int x, y, size, step;
	x = input1;
	y = input2;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	pair<int, int> node, final;
	final = {x, y};
	step = 0;
	int a, b;
	vector<vector<bool>> visited(x + 1, vector<bool> (y + 1, false));
	while(!q.empty()) {
		size = q.size();
		while(size--) {
			node = q.front();
			q.pop();
			a = node.first;
			b = node.second;
			if(visited[a][b])
				continue;
			if(node == final)
				return step;
			visited[a][b] = true;
			if(a + b <= x)
				q.push({a + b, b});
			if(a + b <= y)
				q.push({a, a + b});
		}
		step++;
	}
	return -1;
}

int main(void) {
	int x, y;
	cin>>x>>y;
	cout<<minSteps(x, y)<<endl;
	return 0;
}
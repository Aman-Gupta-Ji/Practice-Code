#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<bool>& visited, vector<vector<int>>& graph, int u, int d) {
	if(visited[u])
		return false;
	if(u == d)
		return true;
	visited[u] = true;
	bool found = false;
	for(int v: graph[u])
		found = found || dfs(visited, graph, v, d);
	return found;
}

int main() {
	int n;
	cin>>n;
	unordered_map<int, int> id;
	int e;
	for(int i = 0; i < n; i++) {
		cin>>e;
		id[e] = i;
	}
	vector<vector<int>> graph(n);
	cin>>e;
	int u, v;
	for(int i = 0; i < e; i++) {
		cin>>u>>v;
		graph[id[u]].push_back(id[v]);
	}
	cin>>u>>v;
	u = id[u];
	v = id[v];
	vector<bool> visited(n, false);
	cout<<dfs(visited, graph, u, v)<<endl;
	return 0;
}
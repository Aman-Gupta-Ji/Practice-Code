bool dfs(vector<bool>& stack, vector<int>& visited, vector<vector<int>>& graph, int i) {
	stack[i]=true;
	visited[i]=true;
	for(int child: graph[i]) {
		if(stack[child])
			return true;
		if(!visited[child])
			if(dfs(stack,visited,graph,child))
				return true;
	}
	stack[i]=false;
	return false;
}

bool isCycle(vector<vector<int>>& graph, int n) {
	vector<bool> stack(n,false);
	vector<int> visited(n,false);
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			if(dfs(stack,visited,graph,i))
				return true;
		}
	}
	return false;
}
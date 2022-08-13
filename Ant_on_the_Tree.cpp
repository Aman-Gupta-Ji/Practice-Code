#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int leaves;
vector<int> res;

bool has(unordered_set<int>& s, int key) {
	return s.find(key)!=s.end();
}

void dfs(vector<bool>& visited, vector<vector<int>>& tree, vector<unordered_set<int>>& childs, int root) {
	visited[root]=true;
	childs[root].insert(root+1);

	bool isleaf=true;
	for(int child: tree[root]) {
		if(!visited[child]) {
			isleaf=false;
			dfs(visited,tree,childs,child);
			childs[root].insert(childs[child].begin(),childs[child].end());
		}
	}

	if(isleaf)
		leaves++;
}

void tripleOrder(vector<bool>& visited, int root, vector<vector<int>>& tree, queue<int>& order, vector<unordered_set<int>>& childs) {
	visited[root]=true;
	if(order.front()==root+1) { // leaf node
		order.pop();
		res.push_back(root+1);
		return;
	}
	bool isPath=true;
	while(isPath) {
		isPath=false;
		if(!order.empty()) {
			for(int child: tree[root]) {
				if(!visited[child]&&has(childs[child],order.front())) {
					res.push_back(root+1);
					tripleOrder(visited,child,tree,order,childs);
					isPath=true;
					break;
				}
			}
		}
	}
	res.push_back(root+1);
}

int main(void) {
	leaves=0;
	int n;
	cin>>n;
	vector<vector<int>> tree(n); // adjcency list

	int s, d;
	for(int i=1;i<n;i++) {
		cin>>s>>d;
		s--;
		d--;
		tree[s].push_back(d);
		tree[d].push_back(s);
	}
	int root=0; // root=1

	vector<bool> visited(n,false);
	vector<unordered_set<int>> childs(n);
	dfs(visited,tree,childs,root);

	queue<int> order;
	for(int i=0;i<leaves;i++) {
		cin>>s;
		order.push(s);
	}

	fill(visited.begin(),visited.end(),false);
	tripleOrder(visited,root,tree,order,childs);
	if(res.size()==2*n-1) {
		for(int i=0;i<2*n-1;i++)
			cout<<res[i]<<' ';
	}
	else
		cout<<-1;
	cout<<endl;
	return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int wb;
int dfs(vector<vector<int>>& graph, int i, string& color) {
	int bal=(color[i]=='W')?1:-1;
	for(int child: graph[i])
		bal+=dfs(graph,child,color);
	if(bal==0)
		wb++;
	return bal;
}
int main(void) {
	int t;
	cin>>t;
	int n, p;
	string color;
	while(t--) {
		cin>>n;
		vector<vector<int>> graph(n);
		for(int i=1;i<n;i++) {
			cin>>p;
			graph[p-1].push_back(i);
		}
		cin>>color;
		wb=0;
		dfs(graph,0,color);
		cout<<wb<<endl;
	}
	return 0;
}
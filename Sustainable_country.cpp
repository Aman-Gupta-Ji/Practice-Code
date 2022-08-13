#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long int

int path;
void backtrack(vector<vector<pair<int,int>>>& graph, int s, int d, vector<bool>& visited, int min_e) {
	if(s==d) {
		path=max(path,min_e);
		return;
	}
	visited[s]=true;
	int c, w;
	for(pair<int,int> node: graph[s]) {
		c=node.first;
		w=node.second;
		if(!visited[c]) {
			backtrack(graph,c,d,visited,min(min_e,w));
		}
	}
	visited[d]=false;
}

ll sum_it(int n, int e, vector<vector<int>>& edges) {
	vector<vector<pair<int,int>>> graph(n);
	int s, d, w;
	int i, j;
	for(i=0;i<e;i++) {
		s=edges[i][0];
		d=edges[i][1];
		w=edges[i][2];
		graph[s].push_back({d,w});
		graph[d].push_back({s,w});
	}
	ll sum=0;
	vector<bool> visited(n,false);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++) {
			path=INT_MIN;
			fill(visited.begin(),visited.end(),false);
			backtrack(graph,i,j,visited,INT_MAX);
			sum+=path;
		}
	return sum;
}

int main(void) {
	int t;
	cin>>t;
	int n, e;
	int s, d, w;
	while(t--) {
		cin>>n>>e;
		vector<vector<int>> edges;
		for(int i=0;i<e;i++) {
			cin>>s>>d>>w;
			s--;
			d--;
			edges.push_back({s,d,w});
		}
		ll sum=sum_it(n,e,edges);
		cout<<sum<<endl;
	}
	return 0;
}
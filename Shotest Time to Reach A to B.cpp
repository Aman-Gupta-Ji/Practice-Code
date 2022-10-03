#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1e16

ll shortestPath(vector<vector<pair<int, ll>>>& graph, int u, int des, int n) {
	vector<ll> dist(n, MAX);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, u));
	ll d, t;
	int v;
	while(!pq.empty()) {
		d = pq.top().first;
		u = pq.top().second;
		pq.pop();
		if(dist[u] <= d)
			continue;
		dist[u] = d;
		for(pair<int, ll>& e: graph[u]) {
			v = e.first;
			t = e.second;
			if(dist[e.first] > d + t)
				pq.push(make_pair(d + t, v));
		}
	}
	return dist[des];
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
	cin>>e;
	int u, v;
	ll d;
	vector<vector<pair<int, ll>>> graph(n);
	for(int i = 0; i < e; i++) {
		cin>>u>>v>>d;
		graph[id[u]].push_back(make_pair(id[v], d));
	}
	cin>>u>>v;
	u = id[u];
	v = id[v];
	d = shortestPath(graph, u, v, n);
	if(d == MAX)
		d = -1;
	cout<<d<<endl;
	return 0;
}
/* Hamiltonian Path is a path in directed or undirected grpah that visit each vertex exactly once.
The problem to check whether a graph (directed or undirected) contains a Hamiltonian Path in NP-complete. */

// Find wheathe Hamiltonian path exists or not

#include<bits/stdc++.h>
using namespace std;

int n, done;

bool memoisation(int s, int bit, vector<vector<bool>>& graph, map<pair<int,int>,bool>& dp) {
	if(bit==done)
		return true;
	pair<int,int> key=make_pair(s,bit);
	if(dp.find(key)!=dp.end())
		return dp[key];
	for(int i=0;i<n;i++)
		if(graph[s][i]&&(bit&(1<<i))==0)
			if(memoisation(i,bit|(1<<i),graph,dp))
				return dp[key]=true;
	return dp[key]=false;
}
int main() {
	int e;
	cin>>n>>e;
	vector<vector<bool>> graph(n,vector<bool> (n,false));
	//adjency matrix
	int s, d;
	for(int i=0;i<e;i++) {
		cin>>s>>d;
		graph[s][d]=true;
	}
	done=(1<<n)-1;
	map<pair<int,int>,bool> dp;
	bool hamiltonian_path=false;
	for(int i=0;i<n;i++) {
		if(memoisation(i,1<<i,graph,dp)) {
			hamiltonian_path=true;
			cout<<true;
			break;
		}
	}
	if(!hamiltonian_path)
		cout<<false;
	return 0;
}
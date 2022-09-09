#include<bits/stdc++.h>
using namespace std;
string dfs(int node,vector<vector<int> >&graph,int parent,const string&s,vector<int>&visit){
	string z="";
	z+=
	visit[node]=true;
	for(int a:graph[node]){
		if(visit[i]==0){
			z+=dfs(a,graph,node,s,visit);
		}
	}
	visit[node]=false;
	return z;
}

int beauty(int n, int m, stirng s, int x[], int y[]) {
	vector<int> parent(n+1);
	for(int i=0;i<=n;i++){
		int par1=parent1(x[i]);
	}
	return ans;
}
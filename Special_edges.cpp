#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int time;
    void dfs(int u,int p, vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, vector<vector<int>>& bridges, vector<bool>& presentInStack, stack<int>& mystack, vector<int>& vsize) {
        disc[u]=low[u]=time++;
        int lower=low[u];
        mystack.push(u);
        presentInStack[u]=true;
        for(int v: graph[u]) {
            if(v==p)
                continue;
            if(disc[v]==-1) {
                dfs(v,u,graph,disc,low,bridges,presentInStack,mystack,vsize);
                if(low[v]>low[u])
                    bridges.push_back({u,v});
                lower=min(lower,low[v]);
            }
            else
                lower=min(lower,disc[v]);
        }
        low[u]=lower;
        stack<int> ns;
        int size, top;
        if(low[u]==disc[u]) {
            while(mystack.top()!=u) {
                top=mystack.top();
                ns.push(top);
                presentInStack[top]=false;
                mystack.pop();
            }
            top=mystack.top();
            ns.push(top);
            presentInStack[top]=false;
            mystack.pop();
            size=ns.size();
            while(!ns.empty()) {
                top=ns.top();
                vsize[top]=size;
                ns.pop();
            }
        }
    }
    void tarjan(int n, vector<vector<int>>& graph, vector<vector<int>>& bridges, vector<int>& vsize) {
        time=0;
        vector<int> disc(n,-1);
        vector<int> low(n);
        vector<bool> presentInStack(n,false);
        stack<int> mystack;
        for(int i=0;i<n;i++)
            if(disc[i]==-1)
                dfs(i,-1,graph,disc,low,bridges,presentInStack,mystack,vsize);
    }
    int calculate(int n, vector<vector<int>>& edges) {
        // call this function
        vector<vector<int>> graph(n);
        int u, v;
        for(vector<int> edge: edges) {
            u=edge[0]-1;
            v=edge[1]-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<vector<int>> bridges;
        vector<int> vsize(n);
        tarjan(n,graph,bridges,vsize);
        int res=0;
        // for(int vs: vsize)
        //     cout<<vs<<" ";
        // cout<<endl;
        for(vector<int> bridge: bridges)
            res+=vsize[bridge[0]]*vsize[bridge[1]];
        return res;
    }
};
int main(void) {
    int t;
    cin>>t;
    int n, e;
    int u, v, i;
    Solution s;
    while(t--) {
        cin>>n>>e;
        vector<vector<int>> edges;
        for(i=0;i<e;i++) {
            cin>>u>>v;
            edges.push_back({u,v});
        }
        cout<<s.calculate(n,edges)<<endl;
    }
    return 0;
}
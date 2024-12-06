#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj, vector<int>& dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<vector<int>> adj(N + 1);
    vector<vector<int>> rev_adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        rev_adj[B].push_back(A);
    }

    int totalCost = 0;

    for (int i = 1; i <= N; ++i) {
        vector<int> dist_orig(N + 1, -1);
        vector<int> dist_rev(N + 1, -1);

        // BFS from city i in the original graph
        bfs(i, adj, dist_orig);
        // BFS from city i in the reversed graph
        bfs(i, rev_adj, dist_rev);

        int cost = 0;

        for (int j = 1; j <= N; ++j) {
            if (dist_orig[j] == -1) cost++;
            if (dist_rev[j] == -1) cost++;
        }

        totalCost += cost;
    }

    cout << totalCost << endl;

    return 0;
}

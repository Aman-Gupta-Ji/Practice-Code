#include <bits/stdc++.h>
using namespace std;

int chain(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
    {
        return 0;
    }

    grid[i][j] = 0;

    return (1 + chain(grid, i + 1, j) + chain(grid, i - 1, j) +
            chain(grid, i, j + 1) + chain(grid, i, j - 1) +
            chain(grid, i - 1, j - 1) + chain(grid, i + 1, j + 1) +
            chain(grid, i - 1, j + 1) + chain(grid, i + 1, j - 1));
}

int TeamBlue(vector<vector<int>> &grid)
{

    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j])
            {
                ans = max(ans, chain(grid, i, j));
            }
        }
    }

    return ans;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> st(n, vector<int>(m));
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> st[i][j];
    cout << TeamBlue(st) << endl;
    return 0;
}
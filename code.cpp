#include<bits/stdc++.h>
using namespace std;

bool maximalSquare(vector<vector<int>>& matrix, int l) {
    int n = matrix.size(), m = matrix[0].size();
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    int max = 0;
    int i, j;
    for(i = 0 ; i < n ; i++) {
        for(j = 0 ; j < m ; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = matrix[i][j] >= l;
            else if(matrix[i][j] >= l)
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            if(dp[i][j] > max)
                max = dp[i][j];
        }
    }
    return max >= l;
}



int main(void) {
    fast;
    clock_t z = clock();
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
    }
    cerr << "Run Time : "<<((double)(clock() - z)/CLOCKS_PER_SEC);
    return 0;
}
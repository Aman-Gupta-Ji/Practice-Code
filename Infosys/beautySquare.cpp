#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Precompute minimum and maximum values for all sub-grids
    vector<vector<vector<int>>> minVal(N, vector<vector<int>>(N, vector<int>(N + 1, INT_MAX)));
    vector<vector<vector<int>>> maxVal(N, vector<vector<int>>(N, vector<int>(N + 1, INT_MIN)));
    
    for (int size = 1; size <= N; ++size) {
        for (int i = 0; i + size <= N; ++i) {
            for (int j = 0; j + size <= N; ++j) {
                if (size == 1) {
                    minVal[i][j][size] = grid[i][j];
                    maxVal[i][j][size] = grid[i][j];
                } else {
                    minVal[i][j][size] = min({minVal[i][j][size - 1], minVal[i + 1][j][size - 1], minVal[i][j + 1][size - 1], minVal[i + 1][j + 1][size - 1]});
                    maxVal[i][j][size] = max({maxVal[i][j][size - 1], maxVal[i + 1][j][size - 1], maxVal[i][j + 1][size - 1], maxVal[i + 1][j + 1][size - 1]});
                }
            }
        }
    }
    
    int maxSumBeauty = 0;
    
    // Store maximum beauty for sub-grids starting from each row and column for efficient lookup
    vector<vector<int>> maxBeautyForRow(N, vector<int>(N, 0));
    vector<vector<int>> maxBeautyForCol(N, vector<int>(N, 0));
    
    for (int size = 1; size <= N; ++size) {
        for (int i = 0; i + size <= N; ++i) {
            for (int j = 0; j + size <= N; ++j) {
                int beauty = maxVal[i][j][size] - minVal[i][j][size];
                maxBeautyForRow[i][j] = max(maxBeautyForRow[i][j], beauty);
                maxBeautyForCol[j][i] = max(maxBeautyForCol[j][i], beauty);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << maxBeautyForRow[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << maxBeautyForCol[i][j] << " ";
        }
        cout << endl;
    }
    
    // Find the maximum beauty sum for non-overlapping sub-grids
    for (int i1 = 0; i1 < N; ++i1) {
        for (int j1 = 0; j1 < N; ++j1) {
            for (int size1 = 1; size1 + i1 <= N && size1 + j1 <= N; ++size1) {
                int beauty1 = maxBeautyForRow[i1][j1];
                
                // Check rows and columns that do not overlap with the first sub-grid
                for (int i2 = i1 + size1; i2 < N; ++i2) {
                    for (int j2 = 0; j2 < N; ++j2) {
                        if (j2 + size1 <= N) {
                            int beauty2 = maxBeautyForRow[i2][j2];
                            maxSumBeauty = max(maxSumBeauty, beauty1 + beauty2);
                        }
                    }
                }
                for (int j2 = j1 + size1; j2 < N; ++j2) {
                    for (int i2 = 0; i2 < N; ++i2) {
                        if (i2 + size1 <= N) {
                            int beauty2 = maxBeautyForCol[j2][i2];
                            maxSumBeauty = max(maxSumBeauty, beauty1 + beauty2);
                        }
                    }
                }
            }
        }
    }
    
    cout << maxSumBeauty << endl;
    
    return 0;
}

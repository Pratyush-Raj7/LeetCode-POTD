class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        vector<pair<int, int>> cells;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) cells.push_back({i, j});
        }
        sort(cells.begin(), cells.end(), [&](auto& a, auto& b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });
        for (int _ = 0; _ <= k; _++) {
            int best = 1e9, sz = cells.size();
            for (int ind = 0; ind < sz; ind++) {
                auto [r, c] = cells[ind];
                best = min(best, dp[r][c]);
                if (ind + 1 < sz and grid[r][c] == grid[cells[ind + 1].first][cells[ind + 1].second]) continue;
                int p = ind;
                while (p >= 0 &&
                       grid[cells[p].first][cells[p].second]
                       == grid[r][c]) {
                    dp[cells[p].first][cells[p].second] = best;
                    p--;
                }
            }
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 and j == n - 1) {
                        dp[i][j] = 0;
                        continue;
                    }
                    if (i + 1 < m) dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i + 1][j]);
                    if (j + 1 < n) dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
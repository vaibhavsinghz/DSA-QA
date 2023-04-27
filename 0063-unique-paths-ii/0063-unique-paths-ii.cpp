class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        if (grid[0][0] or grid[n - 1][m - 1]) return false; // start or end path is blocked
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(i == 1 and j == 1) continue;
                if (grid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else
                    dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
};
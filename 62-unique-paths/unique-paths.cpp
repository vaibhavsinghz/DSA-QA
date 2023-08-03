class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, int m, int n){
        if(i > m || j > n) return 0;
        if(i == m && j == n) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return helper(1, 1, m, n);
    }
};